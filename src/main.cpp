//
// Created by jivko on 13.11.19.
//

//#ifndef TOM_AND_JERRY_PATH_MAIN_CPP
//#define TOM_AND_JERRY_PATH_MAIN_CPP
/*
#include <iostream>
#include <fstream>
#include <string>
#include <zconf.h>
#include "FileExtractor.h"
#include "RoomModel.h"
#include "Step.h"
#include "PathsFinder.h"
#include "InstructionsBuilder.h"
#include "InstructionsTreeFactory.h"
#include "Utility.h"
#include <map>

int main() {

    FileExtractor streamParser("./src/instructions.txt");

    RoomModel room(RawRoomModel(streamParser.extractRawFile()));

    for (int i = 0; i < room.getRoom().size(); ++i) {
        for (int j = 0; j < room.getRoom()[i].size(); ++j) {
            std::cout << room.getRoom()[i][j];
        }
    }
    
    std::cout << std::endl;

    PathsFinder pathsFinder(room);

    InstructionsBuilder builder(room);

    std::vector<DroneInstructions> drInstr;
    for(Path path : pathsFinder.bfsPaths(1000)){
        auto instructions = builder.createInstructionsByPath(path);
        for (auto direction : instructions.getDirections()) {
            std::cout << direction << "  ";
        }

        std::cout << instructions.getTurnCount() << "  ";
        std::cout << instructions.getPlacesToPaint().size() << "  ";
        std::cout << instructions.getStepsCount();
        std::cout << std::endl << std::endl;

        drInstr.push_back(instructions);
    }

    std::cout << std::endl << Utility::get2PaintingInstructions(drInstr).getMaxPaintPlaces() << std::endl;

    TwoDroneInstructions twoDrones = Utility::get2PaintingInstructions(drInstr);
    for (auto direction : twoDrones.getFirstDrone().getDirections()) {
        std::cout << direction << "  ";
    }

    std::cout << std::endl << Utility::getMaxPaintingInstructions(drInstr)->getMaxPaintPlaces() << std::endl;

    InstructionsTreeFactory treeFactory;
    InstructionsTree tree = treeFactory.createTree(drInstr);

    std::ofstream file ("instructionTree.dot");
    tree.dottyPrint(file);
    file.close();

    system("dot instructionTree.dot -Tpng -o instructionTree.png");
    system("feh instructionTree.png");

    return 0;
}*/


#include <iostream>
#include <SFML/Graphics.hpp>

#include <fstream>
#include <string>
#include <zconf.h>
#include "FileExtractor.h"
#include "RoomModel.h"
#include "Step.h"
#include "PathsFinder.h"
#include "InstructionsBuilder.h"
#include "InstructionsTreeFactory.h"
#include "Utility.h"
#include <map>

int main()
{
    // create a window

    sf::RenderWindow window(sf::VideoMode(500, 500), "Sprites & Textures");

    sf::Texture bricks;
    bricks.loadFromFile("/home/jivko/storage/dev projects/c++/Tom-and-Jerry-Path/walls.png");
    sf::Sprite wall;
    wall.setTexture(bricks);
    //wall.setTextureRect(sf::IntRect(0, 0, 64, 64));

    sf::Texture wood;
    wood.loadFromFile("/home/jivko/storage/dev projects/c++/Tom-and-Jerry-Path/floor.png");
    sf::Sprite floor;
    floor.setTexture(wood);

    sf::Texture cat;
    cat.loadFromFile("/home/jivko/storage/dev projects/c++/Tom-and-Jerry-Path/tom.png");
    sf::Sprite tom;
    tom.setTexture(cat);

    sf::Texture mouse;
    mouse.loadFromFile("/home/jivko/storage/dev projects/c++/Tom-and-Jerry-Path/jerry.png");
    sf::Sprite jerry;
    jerry.setTexture(mouse);

    sf::Texture vehicle;
    vehicle.loadFromFile("/home/jivko/storage/dev projects/c++/Tom-and-Jerry-Path/drone.png");
    sf::Sprite drone;
    drone.setTexture(vehicle);

    sf::Texture green;
    green.loadFromFile("/home/jivko/storage/dev projects/c++/Tom-and-Jerry-Path/paint.png");
    sf::Sprite paint;
    paint.setTexture(green);

    FileExtractor streamParser("./src/instructions.txt");

    RoomModel room(RawRoomModel(streamParser.extractRawFile()));

    for (int i = 0; i < room.getRoom().size(); ++i) {
        for (int j = 0; j < room.getRoom()[i].size(); ++j) {
            std::cout << room.getRoom()[i][j];
        }
    }

    sf::Event event;

    auto wbounds = wall.getGlobalBounds();
    auto fbounds = floor.getGlobalBounds();
    auto tbounds = tom.getGlobalBounds();
    auto jbounds = jerry.getGlobalBounds();

    drone.setPosition({ tbounds.width * (room.getTomPosition().getX() + 1), tbounds.height * (room.getTomPosition().getY() + 1)});

    PathsFinder pathsFinder(room);

    InstructionsBuilder builder(room);

    std::vector<DroneInstructions> drInstr;
    for(Path path : pathsFinder.bfsPaths(1000)){
        auto instructions = builder.createInstructionsByPath(path);

        drInstr.push_back(instructions);
    }

    auto droneInstructions = drInstr.back();
    auto droneIter = droneInstructions.getPathCoordinates().getIterator();

    std::list<Point> alreadyPainted;

    sf::Clock clock;
    //sf::Time time = clock.getElapsedTime();
    clock.restart();


    // game loop
    while (window.isOpen())
    {
        // poll events

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::W)
                    floor.move(0, -64);
                if (event.key.code == sf::Keyboard::D)
                    tom.move(64, 0);
                if (event.key.code == sf::Keyboard::S)
                    floor.move(0, 64);
                if (event.key.code == sf::Keyboard::A)
                    floor.move(-64, 0);
            }
        }

        sf::Time time = clock.getElapsedTime();
        if (time.asSeconds() >= 1.15 && droneIter.valid()){
            droneIter.next();

            Point nextPoint = droneIter.get();
            drone.setPosition(tbounds.width * (nextPoint.getX() + room.WALLS_OFFSET), tbounds.height * (nextPoint.getY() + room.WALLS_OFFSET));
            if(std::find(droneInstructions.getPlacesToPaint().begin(), droneInstructions.getPlacesToPaint().end(), nextPoint) !=  droneInstructions.getPlacesToPaint().end()){
                alreadyPainted.push_back(nextPoint);
            }
            clock.restart();
        } else if (!droneIter.valid()){
            drone.setPosition(tbounds.width * (room.getJerryPosition().getX() + room.WALLS_OFFSET), tbounds.height * (room.getJerryPosition().getY() + room.WALLS_OFFSET));
        }

        window.clear(sf::Color::White);


        for (int i = 0; i < room.getRoom().size(); ++i) {
            for (int j = 0; j < room.getRoom()[i].size(); ++j) {
                if(room.getRoom()[j][i] == '1'){

                    wall.setPosition({ wbounds.width * i, wbounds.height * j });
                    window.draw(wall);
                } else if(room.getRoom()[j][i] == 't'){

                    floor.setPosition({ fbounds.width * i, fbounds.height * j });
                    window.draw(floor);
                    tom.setPosition({ tbounds.width * i, tbounds.height * j });
                    window.draw(tom);
                } else if(room.getRoom()[j][i] == 'j'){

                    floor.setPosition({ fbounds.width * i, fbounds.height * j });
                    window.draw(floor);
                    jerry.setPosition({ jbounds.width * i, jbounds.height * j });
                    window.draw(jerry);
                } else {

                    floor.setPosition({ fbounds.width * i, fbounds.height * j });
                    window.draw(floor);
                }
            }
        }

        for (auto iter = alreadyPainted.begin(); iter != alreadyPainted.end(); ++iter) {
            paint.setPosition({ tbounds.width * (iter->getX() + room.WALLS_OFFSET), jbounds.height *  (iter->getX() + room.WALLS_OFFSET) });
            window.draw(paint);
        }

        window.draw(drone);

        window.display();
    }

    return 0;
}

//#endif //TOM_AND_JERRY_PATH_MAIN_CPP
