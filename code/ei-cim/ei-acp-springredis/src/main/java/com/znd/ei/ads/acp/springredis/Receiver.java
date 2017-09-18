package com.znd.ei.ads.acp.springredis;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;

import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.adf.DataFieldStorage;

public class Receiver {
    private static final Logger LOGGER = LoggerFactory.getLogger(Receiver.class);

   // private CountDownLatch latch;
    @Autowired
    private DataFieldStorage storage;
//    @Autowired
//    public Receiver(CountDownLatch latch) {
//        this.latch = latch;
//    }
    public Receiver() {
    }
    public void receiveMessage(String message) throws ACPException, UnsupportedOperation {
        LOGGER.info("Received <" + message + ">");
        
        int pos = message.indexOf(':');
        
        String contentCode = message.substring(0, pos);
        String content = message.substring(pos+1);
        storage.receivedMessage(contentCode, content);
        
        
       // latch.countDown();
    }
}
