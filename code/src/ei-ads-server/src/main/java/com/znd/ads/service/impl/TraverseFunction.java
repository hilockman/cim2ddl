package com.znd.ads.service.impl;

import java.io.File;

public interface TraverseFunction {
	ModelItem visit(ModelItem parent, ModelItem item, File file);
}
