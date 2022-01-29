//
//  Server.hpp
//  ft_irc_teamwork
//
//  Created by Esperanza Zachariah on 1/29/22.
//  Copyright © 2022 Esperanza Zachariah. All rights reserved.
//

#ifndef Server_hpp
#define Server_hpp

// MARK: - C++ headers
#include <map>
#include <string>
#include <csignal>
#include <vector>
#include <sstream>
#include <iostream>
#include <exception>
#include <algorithm>

// MARK: - C headers
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

// MARK: headers
#include "../Utils/Colors.hpp"

// MARK: - IRC namespace

namespace IRC {
	
	// MARK: - Server
	
	class Server {
	
	// MARK: - Public
	public:
		Server(unsigned int const &port, std::string const &password);
		virtual ~Server();
		
		void start();
	
	// MARK: - Private
	private:
		// MARK: - Values
		unsigned int port;
		std::string password;
		
		int listenSocket;
		int maxFd;
		fd_set masterSet;
		struct sockaddr_in addr;
		// MARK: - Methods
		
		void execute();
		
		void nick();
		void pass();
		void user();
		
	};
	
}

#endif /* Server_hpp */
