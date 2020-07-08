#pragma once
#ifndef RESOURCELOADER_H
#include "Globals.h"





enum class EntityType;
enum class ObjectType;
enum class ResourceType;

class Resource;
enum class ResourceType  {
	Image,
	SpriteSheet,
	Audio,
	Effects,
	None

};

// other information about entity such as position name entity type blah blah
class ConfigurationData {

public:


	// Constructor should set all private variables
	ConfigurationData(EntityType et, std::string name, ObjectType ot, Resource* rs);
	ConfigurationData();
	void addEntityType(EntityType);
	void addEntityName(std::string&);
	void addObjectType(ObjectType);
	void addResource(Resource*);



	// get values
    [[nodiscard]]
	EntityType getEntityType() const { return entityType; }
    [[nodiscard]]
	ObjectType getObjectType() const { return objectType; };
    [[nodiscard]]
	Resource* getResources() const { return resources; };
    [[nodiscard]]
	std::string getName() const { return entityName; };


	// Delete the vector array
	~ConfigurationData();

private:



	Resource* resources;
	std::string entityName;
	EntityType entityType;
	ObjectType objectType;

};

class Resource {

public:
	std::string path;
	ResourceType type = ResourceType::None;
	sf::Texture thisTexture;
    ~Resource () {};
};

class ResourceLoader
{
public:
    // Will probably be updated soon. Load texture and return a resource
    // we will return a Array of resource soon based on a configuration file
    [[nodiscard]]
	std::vector<ConfigurationData*> loadEntityResourceConfig(std::string filepath);

    [[nodiscard]]
	ConfigurationData* createEntityConfig(std::string configData);



private:
    [[nodiscard]]
	EntityType getEntityTypeFromToken(const std::string &);
    [[nodiscard]]
	ObjectType getObjectTypeFromToken(const std::string &);




	// we need to make sure the resource can actually be located
	// if cant locate anything return false and set resource to null
    [[nodiscard]]
	bool CreateResourceStaticImage(Resource&,const std::string&);
    [[nodiscard]]
	bool CreateResourceSpriteSheet(Resource&, std::string);
    [[nodiscard]]
	bool CreateResourceAudio(Resource&, std::string);
    [[nodiscard]]
	bool CreateResourceEffect(Resource&, std::string);
};





#endif //// RESOURCELOADER_H
