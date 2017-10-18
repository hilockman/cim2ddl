package com.znd.ei.codegen.service;

import java.util.ArrayList;
import java.util.List;


public class CodeBlockNode  {

	
	private CodeBlockNode parent;
	private List<CodeBlockNode> childs;
	
	private CodeBlock block;
	
	public CodeBlockNode() {
		childs = new ArrayList<CodeBlockNode>();
	}
	
	public CodeBlockNode(CodeBlock block) {
		childs = new ArrayList<CodeBlockNode>();
		this.block = block;
	}
	
	public void addChild(CodeBlockNode node) {
		node.setParent(this);
		childs.add(node);
	}

	public CodeBlockNode getParent() {
		return parent;
	}

	public void setParent(CodeBlockNode parent) {
		this.parent = parent;
	}
	
	public CodeBlockNode add(CodeBlock block) {
		CodeBlockNode node = new CodeBlockNode(block);
		addChild(node);
		return node;
	}

	public CodeBlock getBlock() {
		return block;
	}

	public void setBlock(CodeBlock block) {
		this.block = block;
	}
	
	public int getSize() {
		if (childs != null)
			return childs.size();
		
		return 0;
	}


	public List<CodeBlockNode> getChilds() {
		return childs;
	}

	public void setChilds(List<CodeBlockNode> childs) {
		this.childs = childs;
	}
}
