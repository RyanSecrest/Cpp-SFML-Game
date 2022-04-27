/*
RYAN SECREST
PA9 Game Title : " Box Invasion " 

desc:
    A 2d game where you shoot down the enemies raining from above.

Credits:
    -Artwork by Ryan Secrest
    -Music created by Adrian Smith
    -Sound Effects taken from youtube
    -Code layout learned from SFML dev website and Youtube tutorials.
*/

#include "Game.h"
#include <time.h>

int main() // failed at network implementation
{
   /* sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    sf::TcpSocket socket;
    char buffer[1000];
    std::size_t received;

    char choice;
    std::string line = "Connected to: ";

    std::cout << "Server (s)\nClient (c)";
    std::cin >> choice;

    if (choice == 's')
    {
        sf::TcpListener listener;
        listener.listen(1000);
        listener.accept(socket);
        line += "SERVER";
        socket.send(line.c_str(), line.length() + 1);
    }
    else if (choice == 'c')
    {
        socket.connect(ip, 1000);
        line += "CLIENT";
        socket.send(line.c_str(), line.length() + 1); 
    }

    socket.receive(buffer, sizeof(buffer), received);
    std::cout << buffer<<"\n";
    */

    srand(time(static_cast<time_t*>(0)));

    Game game;

    game.run();

    return 0;
}