// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "ResourceLoader.h"


/*
Resource* ResourceLoader::loadResource(std::string path, ResourceType resourceType)
{


	Resource* resource = new Resource;


	switch (resourceType)
	{
		case ResourceType::Image:
			
			if (CreateResourceStaticImage(*resource, path)) {

				return resource;
			}
			else
			{
				delete resource;
			}

		break;
	};


	return nullptr;
}
*/


std::vector<ConfigurationData*> ResourceLoader::loadEntityResourceConfig(std::string filepath)
{
    
#if __APPLE__
    filepath = "Resources/" + filepath;
#endif
    
	std::vector<ConfigurationData*> DataConfigVector;
	std::ifstream config(filepath);

	if (!config.good())
	{

		printf("[!] Failed to load Entity Configuration file : %s\n", filepath.c_str());
		return std::vector <ConfigurationData*>();
	}
	// opened up
	
	std::string line;
	


	
	bool startEntity = false;
	std::string EntityDataString = "";
	while (std::getline(config, line))
	{

       
		// skips the line with a * anywhere in it
		if (line.find('*') != std::string::npos)
		{
			continue;
		}

		// we will need to do a bunch of if or cases here
		std::istringstream buf(line);
		std::istream_iterator<std::string> beg(buf), end;
		std::vector<std::string> tokens(beg, end);



		if (!tokens.empty())
		{
			if (tokens[0] == "START_ENTITY")
			{
				startEntity = true;

				EntityDataString = tokens[0] + " " + tokens[1] + " " + tokens[2] + "\n";



				continue;
			}

			if (tokens[0] == "END_ENTITY")
			{
				//printf("[+] Entity Data: \n%s", EntityDataString.c_str());

				// we will call create entity configuration

				ConfigurationData* ptr = createEntityConfig(EntityDataString);
				if (ptr != nullptr)
					DataConfigVector.push_back(ptr);

				ptr = nullptr;

				startEntity = false;
				EntityDataString.clear();
				continue;
			}

			if (startEntity)
			{
				if (tokens.size() == 1)
				{
					EntityDataString += tokens[0] + "\n";
					continue;
				}

				EntityDataString += tokens[0] + " " + tokens[1] + "\n";

				
			}
		}

		tokens.clear();
	}




	// issue is multiple objects under one entity type. How to access those?

	config.close();


	if (!DataConfigVector.empty())
	{
		return DataConfigVector;
	}
	else
		return std::vector <ConfigurationData*>();
//return std::vector<std::pair<EntityType, std::vector<Resource*>>>();
}

ConfigurationData* ResourceLoader::createEntityConfig(std::string configData)
{

	ConfigurationData* configPointer = new ConfigurationData;

	Resource* resource = new Resource;
	std::istringstream iss(configData);

	// go through configuration data
	std::string line;
	while (std::getline(iss, line))
	{

		std::istringstream buf(line);
		std::istream_iterator<std::string> beg(buf), end;
		std::vector<std::string> tokens(beg, end);

		if (tokens[0] == "START_ENTITY")
		{
			//configPointer = new ConfigurationData;
            //configPointer (new ConfigurationData);


			configPointer->addObjectType(getObjectTypeFromToken(tokens[1]));
			configPointer->addEntityType(getEntityTypeFromToken(tokens[2]));
			
		}
		
		
		if (tokens[0] == "Name")
		{
			if (tokens.size() == 2)
			{
				configPointer->addEntityName(tokens[1]);
			}
		}

		if (tokens[0] == "StaticImage")
		{
			if (tokens.size() == 2)
			{
                 resource->path = tokens[1];
                   
                   #if __APPLE__
                       resource->path = "Resources/" + resource->path;
                   #endif
                    
				///resource->path = tokens[1];

				// need to create Texture
				if (!CreateResourceStaticImage(*resource, resource->path))
				{
					// failed to load Texture. Crash program
					delete configPointer;
					configPointer = nullptr;
					break;
				}
			}
		}

		if (tokens[0] == "SpriteSheet")
		{
			if (tokens.size() == 2)
			{

			}
		}

		if (tokens[0] == "Audio")
		{
			if (tokens.size() == 2)
			{

			}
		}
		if (tokens[0] == "Effects")
		{
			if (tokens.size() == 2)
			{
			}
		}
		
	}

	if (configPointer)
        configPointer->addResource(resource);
  //  if (!resource){
	//	delete resource;
        
    //}


	return configPointer;
}

EntityType ResourceLoader::getEntityTypeFromToken(const std::string &typ)
{
	EntityType etype = EntityType::None;


    // make modular
    
	if (typ == "Player")
	{
		etype = EntityType::Player;
	}
	if (typ == "Enemy")
	{
		etype = EntityType::Enemy;
	}
    if (typ == "Background")
    {
        etype = EntityType::Background;
    }
    if (typ == "Platform")
    {
        etype = EntityType::Platform;
    }
    if (typ == "StaticBackground")
    {
        etype = EntityType::StaticBackground;
    }
    if (typ == "UI_Image")
    {
        etype = EntityType::UI_Image;
    }
    if (typ == "Projectile")
    {
        etype = EntityType::Projectile;
    }
    /*
     Player,
     Enemy
     Background,
     Platform,
     None

     */



	return etype;
}

ObjectType ResourceLoader::getObjectTypeFromToken(const std::string &typ)
{

	ObjectType otype = ObjectType::None;

	if (typ == "Dynamic")
	{
		otype = ObjectType::Dynamic;
	}

	if (typ == "Static")
	{

		otype = ObjectType::Static;
	}
    if (typ == "Scenery")
    {
        otype = ObjectType::Scenery;
    }
    if (typ == "UI")
    {
        otype = ObjectType::UI;
    }
	return otype;
}



bool ResourceLoader::CreateResourceStaticImage(Resource& resource, const std::string &path)
{
	resource.path = path;
	resource.type = ResourceType::Image;

	//load the texture
	if (!resource.thisTexture.loadFromFile(path))
	{
		printf("[+] Texture did not load %s\n", path.c_str());
		return false;
	}

	printf("[+] Texture loaded %s\n", path.c_str());
	return true;
}



ConfigurationData::ConfigurationData(EntityType et, std::string name, ObjectType ot, Resource* rs)
{


	// issue is not reusing resources

	this->entityType = EntityType::None;
	this->objectType = ObjectType::None;
	this->resources = nullptr;

	if (et != EntityType::None)
	{
		this->addEntityType(et);
	}
	if (!name.empty())
	{
		
		this->addEntityName(name);
	}
	if (ot != ObjectType::None)
	{
		this->addObjectType(ot);
	}
	if (rs != nullptr)
	{
		this->addResource(rs);
	}


}

ConfigurationData::ConfigurationData()
{
	this->entityType = EntityType::None;
	this->objectType = ObjectType::None;
	this->resources = nullptr;
}

void ConfigurationData::addEntityType(EntityType et)
{
	this->entityType = et;
}

void ConfigurationData::addEntityName(std::string& name)
{
	this->entityName = name;
}

void ConfigurationData::addObjectType(ObjectType ot)
{
	this->objectType = ot;
}

void ConfigurationData::addResource(Resource* rs)
{
	this->resources = rs;
}

ConfigurationData::~ConfigurationData()
{
	// delete all
	
	//if (this->resources != nullptr)
	//{
        
	delete this->resources;
	//}



}
