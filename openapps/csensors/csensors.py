import os
import sys
here = sys.path[0]
print here
sys.path.insert(0,os.path.join(here,'..','..','..','coap'))

from coap import coap
import signal

MOTE_IP_0 = 'bbbb::1060:1213:7cca:52cc'
MOTE_IP_1 = 'bbbb::5073:1b2a:aa69:ac3f'
MOTE_IP_2 = 'bbbb::907e:c637:118a:456e' #DAG_Root
MOTE_IP_3 = 'bbbb::1723:c1da:bb3e:655a'
UDPPORT = 61618 # can't be the port used in OV

c = coap.coap(udpPort=UDPPORT)

# read the information about the board status
p = c.GET('coap://[{0}]/s/c'.format(MOTE_IP_0))
print ''.join([(chr(int(b))) for b in p])

# read the information about the board status
#p = c.GET('coap://[{0}]/t'.format(MOTE_IP_1))
#print ''.join([chr(b) for b in p])

# read the information about the board status
#p = c.GET('coap://[{0}]/t'.format(MOTE_IP_2))
#print ''.join([chr(b) for b in p])

# read the information about the board status
#p = c.GET('coap://[{0}]/t'.format(MOTE_IP_3))
#print ''.join([chr(b) for b in p])



while True:
        input = raw_input("Done. Press q to close. ")
        if input=='q':
            print 'bye bye.'
            #c.close()
            os.kill(os.getpid(), signal.SIGTERM)
