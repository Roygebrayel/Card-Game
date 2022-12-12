cmake_minimum_required(VERSION 3.24)
project(Card_Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Card_Game
        .idea/.gitignore
        .idea/Card-Game.iml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        .gitignore
        DLL.cpp
        function.cpp
        LICENSE.md
        PlayerLinkedList.cpp
        queue.cpp
        Stacks.cpp)
