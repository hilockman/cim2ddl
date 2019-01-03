package com.znd.ei;

import java.io.IOException;
import java.net.URL;
import java.util.jar.JarInputStream;

public interface JarStreamFactory {

	JarInputStream createStream(URL path) throws IOException;
	
	
	final static JarStreamFactory  dafaultFactory = new JarStreamFactory() {
		
		@Override
		public JarInputStream createStream(URL path) throws IOException {			
        	JarInputStream jis = new JarInputStream(path.openStream());
        	return jis;
		}
	};
}
