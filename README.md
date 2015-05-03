# p2psdk
A p2p SDK for iOS and Android, works on UDP.

Establishing P2P link involves 3 steps:
1, get local sdp with P2PSDK.prepare, you will receive local sdp in IP2PListener.onPrepared.
2, send the local sdp to peer (with your signal server).
3, call P2PSDK.punch when receive remote_sdl from peer.


Code sample:
1, create a P2PListener object, which implements IP2PListener.
2, in P2PListener.onPrepared, send the local sdp to peer with some kind of signal.
3, when get remote_sdl from peer, call punch.

class P2PListener : public IP2PListener
{
public:
    virtual void    onPrepared(const char* sdp) {
        printf("onPrepared\n");
    }
    
    virtual void    onConnected() {
        printf("onConnected\n");
    }
    
    virtual void    onDisconnected() {
        printf("onDisconnected\n");
    }
    
    virtual void    onData(const char*buf, int len) {
        printf("onData\n");
    }
};

@implementation P2PService
{
    P2PListener*    m_pP2PListener;
    P2PSDK* m_pP2PSDK;
}

static P2PService* s_pP2PSvc = nil;

+ (instancetype) instance
{
    if( s_pP2PSvc == nil ) {
        s_pP2PSvc = [[P2PService alloc] init];
    }
    
    return s_pP2PSvc;
}

- (id) init
{
    self = [super init];
    if( self ) {
        m_pP2PListener = new P2PListener();
        m_pP2PSDK = new P2PSDK(m_pP2PListener);
    }
    
    return self;
}

- (void) startP2PEngine
{
    m_pP2PSDK->prepare();
}

- (void) punch:(NSString*)remote_sdl
{
    m_pP2PSDK->punch(remote_sdl);
}
