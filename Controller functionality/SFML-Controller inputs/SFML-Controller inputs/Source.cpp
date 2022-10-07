#include <sfml/Window.hpp>
#include <SFML/Graphics.hpp>
#include <sfml/Window/Joystick.hpp>

int positionX;
int positionY;

using namespace sf;
bool prActive = false;
int main()
{
    // create the window
    RenderWindow window(VideoMode(800, 600), "My window");
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(Color::Black);

        //creating a rectangle to repersent our player
        RectangleShape playerRect(Vector2f(12.0f, 12.0f));
        if (prActive==false)
        {
            playerRect.setPosition(400, 400);
            prActive == true;
        }

            positionX = playerRect.getPosition().x;
            positionY = playerRect.getPosition().y; //these might not be needed but eh

            if (Joystick::isConnected(0))
            {
                playerRect.setFillColor(sf::Color(150, 50, 250)); //visual confirm its connected
                positionX = positionX + Joystick::getAxisPosition(0, sf::Joystick::X);
                positionY = positionY + Joystick::getAxisPosition(0, sf::Joystick::Y);
                //Joystick::update();

            }

            //trying the A button for now
            if (Joystick::isButtonPressed(0, 0)) //0th joystick, B on Switch pro is B button
            {
                playerRect.setFillColor(sf::Color(0, 50, 250)); //visual confirm its pressed
            }
            else if (Joystick::isButtonPressed(0, 1)) //oth joystick, A on switch pro is a button 
            {
                playerRect.setFillColor(sf::Color(50, 0, 100)); //visual confirm its pressed
            }
            else if (Joystick::isButtonPressed(0, 2)) //oth joystick, Y on swich pro [i was guessing it was anticlockwise starting at B but guess not]
            {
                playerRect.setFillColor(sf::Color(150, 0, 0)); //visual confirm its pressed
            }
            else if (Joystick::isButtonPressed(0, 3)) //0th joystick, 
            {
                playerRect.setFillColor(sf::Color(255, 255, 255)); //visual confirm its pressed
            }


            playerRect.setPosition(positionX, positionY);

        


        // draw everything here...
        // window.draw(...);
        window.draw(playerRect);

        // end the current frame
        window.display();
    }

    return 0;
}

