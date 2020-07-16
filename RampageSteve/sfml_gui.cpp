// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "sfml_gui.h"


using namespace SFML_GUI;
//using namespace SFML_GUI::GUI_items;




sf::Vector2f getScreenPosition_vertical (SCREEN_POSITION_VERTICAL POSITION)
{
    /*
    
    if (POSITION == SFML_GUI::SCREEN_POSITION_VERTICAL::TOP)
    {
        // the top
        return sf::Vector2f();
    }
    if (POSITION == SFML_GUI::SCREEN_POSITION_VERTICAL::MIDDLE)
    {
        // the top
        return sf::Vector2f();
    }
    if (POSITION == SFML_GUI::SCREEN_POSITION_VERTICAL::BOTTOM)
    {
        // the top
        return sf::Vector2f();
    }
    */
    return sf::Vector2f ();
}


// CONSTRUCT BASE CLASS TO POINT THE TEXTURE CORRECTLY

GUI_Component::GUI_Component(const sf::Texture* texture) : sf::Sprite (*texture)
{
    this->isClicked = false;
    this->clickCBPtr = nullptr;
}
void GUI_Component::setOnClickCallBackFunction(callBackFunc cb){
    
    this->clickCBPtr = cb;
    
}

GUI_Component::~GUI_Component (){
    // no need to delete function pointer
    //https://bytes.com/topic/c/answers/504956-do-you-have-delete-function-pointer
}

// MENU BUTTON DEF

SFML_GUI::GUI_items::MenuItem::MenuItem (const sf::Texture* texture) : GUI_Component (texture)
{
    
    
    if (!this->init ())
    {
        
    }
}
    

bool SFML_GUI::GUI_items::MenuItem::init ()
{
    
    
    
    this->clickCBPtr = nullptr;
    
    this->setOrigin(this->getLocalBounds().width/2, this->getLocalBounds().height/2);
    
    
    
    
    this->isClicked = false;
    return true;
}

// update
void SFML_GUI::GUI_items::MenuItem::update (const float&)
{
    
}

// render
void SFML_GUI::GUI_items::MenuItem::render(sf::RenderTarget* target)
{
    target->draw(*this);
}

// update input
void SFML_GUI::GUI_items::MenuItem::updateInput (const float&, const sf::Event * event)
{
    if (event->type == sf::Event::MouseButtonPressed)
    {
        float mX = (float) event->mouseButton.x;
        float mY = (float) event->mouseButton.y;
        
        if (this->getGlobalBounds().contains(mX, mY))
        {
            this->isClicked = true;
            // we will need to eventually handle reseting
            // we need to define this as a OnClick Pointer
            if (this->clickCBPtr != nullptr)
                this->clickCBPtr();
            
            
            
        }
        
        
    }
  
}

SFML_GUI::Layout::Layout (const sf::Vector2f &pos) : sf::Transformable (){
    
    //this->layoutComponents = new GUI_Component[size];
    
    this->setPosition(pos);
    
    
}

SFML_GUI::UI_Layouts::MainMenuFlowLayout::MainMenuFlowLayout(const unsigned size, const sf::Vector2f& pos) : Layout(pos), menuItemsArray{new GUI_items::MenuItem * [(size_t)size] }, sizeOfItemArray{ size }
{
    
    
    if (!this->init())
    {
        
    }
}


// work in progress
SFML_GUI::UI_Layouts::MainMenuFlowLayout::MainMenuFlowLayout (const unsigned size, const SFML_GUI::SCREEN_POSITION_VERTICAL POSITION) : Layout(sf::Vector2f (0,0))
{
    // we need to set position
    this->menuItemsArray = new GUI_items::MenuItem * [(size_t)size];
    this->sizeOfItemArray = size;
    
    if (POSITION == SFML_GUI::SCREEN_POSITION_VERTICAL::TOP)
    {
        // the top
    }
    if (POSITION == SFML_GUI::SCREEN_POSITION_VERTICAL::MIDDLE)
    {
        // the top
    }
    if (POSITION == SFML_GUI::SCREEN_POSITION_VERTICAL::BOTTOM)
    {
        // the top
    }
    
    if (!this->init())
    {
        
    }
    
}

bool SFML_GUI::UI_Layouts::MainMenuFlowLayout::init (){
    
    
    
    
    
    return true;
    
}
    
void SFML_GUI::UI_Layouts::MainMenuFlowLayout::update (const float&){
    // Prob not going to be used
}
    
void SFML_GUI::UI_Layouts::MainMenuFlowLayout::render (sf::RenderTarget* target)
{
    
    
    
    if (this->menuItemsArray != nullptr)
    {
        for (unsigned i = 0; i < this->sizeOfItemArray; i ++)
        {
            target->draw(*this->menuItemsArray[(size_t)i]);
        }
        
        
    }
}

void SFML_GUI::UI_Layouts::MainMenuFlowLayout::updateInput(const float &dt, const sf::Event *event){
    if (this->menuItemsArray != nullptr)
    {
        for (unsigned i = 0; i < this->sizeOfItemArray; i ++)
        {
            this->menuItemsArray[(size_t)i]->updateInput(dt, event);
        }
        
        
    }
}
bool SFML_GUI::UI_Layouts::MainMenuFlowLayout::AddItem (GUI_Component* item, const float marginH){
    
    
    if (this->currIncrement == this->sizeOfItemArray)
    {
        
        printf ("Size of array is at LIMIT. MainMenuFlowLayout\n");
        return false;
    }
    
    
    // a cast to the GUI Comp to make it a menuitem
    this->menuItemsArray [(size_t)this->currIncrement] = (GUI_items::MenuItem *) item;
    this->currIncrement ++;
    
    //We can Position items here
   
    
    // We will position in the center then we will add the relative path to the current position
    
    // position with a Y offset
    item->setPosition(this->getPosition().x,this->getPosition().y + this->offset);
    
    // padding underneath each element
    this->offset += (unsigned) (item->getTextureRect().height + marginH);
    

    
 
    return true;
}
void SFML_GUI::UI_Layouts::MainMenuFlowLayout::rePositionElements ()
{
    
    // More research on this
    
    // make sure there are elements contained
    if (this->currIncrement > 0)
    {
        
        for (unsigned i = 0; i < this->sizeOfItemArray - 1; i ++)
        {
            // this isn't working properly we should fix
            
            this->menuItemsArray[(size_t)i]->setPosition(this->menuItemsArray[(size_t)i]->getPosition().x, 
                this->menuItemsArray[(size_t)i]->getPosition().y - this->menuItemsArray[(size_t)i]->getTextureRect().height);
            
        }
        
    }
    
        
}


SFML_GUI::UI_Layouts::MainMenuFlowLayout::~MainMenuFlowLayout(){
    // delete mah pointers
    
    if (this->menuItemsArray != nullptr)
    {
        
        for (unsigned i = 0; i < this->sizeOfItemArray; i ++)
        {
            delete this->menuItemsArray [(size_t)i];
        }
        
        delete [] this->menuItemsArray;
    }
    
}

