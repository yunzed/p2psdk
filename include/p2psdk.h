//
//  p2psdk.h
//  p2psdk
//
//  Created by Yunze Deng on 12/6/14.
//  Copyright (c) 2014 Yunze Deng. All rights reserved.
//

#ifndef _P2PSDK_H_
#define _P2PSDK_H_

class P2PEngine;

struct IP2PListener {
    virtual void    onPrepared(const char* sdp) = 0;
    virtual void    onConnected() = 0;
    virtual void    onDisconnected() = 0;
    virtual void    onData(const char*buf, int len) = 0;
};

class P2PSDK {
public:
    P2PSDK(IP2PListener* listener);
    ~P2PSDK();
    
public:
    void    prepare();
    void    punch(char* sdp);
    void    release();
    void    send(const char* buf, int len);
    
private:
    P2PEngine*  m_pEngine;
};


#endif
