package com.znd.bus.server;

public class Topic {

	private VerbEnum verb;
	private String noun;
	public Topic(VerbEnum verb, String noun) {
		this.verb = verb;
		this.noun = noun;
	}
	
	public VerbEnum getVerb() {
		return verb;
	}
	public void setVerb(VerbEnum verb) {
		this.verb = verb;
	}
	public String getNoun() {
		return noun;
	}
	public void setNoun(String noun) {
		this.noun = noun;
	}
	
	public String getName() {
		return formName(verb, noun);
	}
	
	public static String formName(VerbEnum verb, String noun) {
		return verb.name() + '_' + noun;
	}
	
	public static Topic parse(String name) {
		int pos = name.indexOf('_');
		if (pos < 0)
			return null;
		
		VerbEnum verb = Enum.valueOf(VerbEnum.class, name.substring(0, pos));
		String noun = name.substring(pos + 1);
		
		return new Topic(verb, noun);
	}
}
