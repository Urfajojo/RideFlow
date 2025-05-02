//
// Created by Owner on 4/30/2025.
//

#ifndef OPENSOCKET.H
#define OPRNSOCKET.H

class OpenSocket;

int openSocket(const char* interfacename);

static int sock;
static int socklen;
static int sockaddr_len;
static bool isopen;

#endif //OPENSOCKET.H