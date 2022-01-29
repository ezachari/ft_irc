//
//  main.cpp
//  ft_irc_teamwork
//
//  Created by Esperanza Zachariah on 1/29/22.
//  Copyright © 2022 Esperanza Zachariah. All rights reserved.
//

#include "Server/Server.hpp"

int main(int argc, const char * argv[]) {
    
    switch (argc) {
        case 3:
			try {
				unsigned int port = std::atoi(argv[1]);
				std::string password = std::string(argv[2]);
				
				IRC::Server server = IRC::Server(port, password);;
			} catch(std::exception const &e) {
				std::cerr << RED << e.what() << RESET << std::endl;
				exit(1);
			}
			break;
        default:
            std::cout << RED << "Использование: ./ircserv <port> <password>" << RESET << std::endl;
			std::cout << YELLOW << "   port - номер порта на котором будет расположен IRC сервер" << RESET << std::endl;
			std::cout << YELLOW << "   password - пороль для подключения к серверу" << RESET << std::endl;
			std::cout << YELLOW << "   EXAMPLE: ./ircserver 42000 1234" << RESET << std::endl;
            exit(1);
    }
    return 0;
}
