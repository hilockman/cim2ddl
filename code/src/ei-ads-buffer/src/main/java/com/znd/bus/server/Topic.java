package com.znd.bus.server;

public class Topic {

	private VerbEnum verb;
	private String noun;
	
	
	public static class TopicEnd {

		private Topic topic;
		private Direction direction;
		
		private TopicEnd(VerbEnum verb, String noun, Direction direction) {
			this.direction = direction;
			this.setTopic(new Topic(verb, noun));
		}
		
		private TopicEnd(VerbEnum verb, NounEnum noun, Direction direction) {
			this.direction = direction;
			this.setTopic(new Topic(verb, noun.name()));
		}
		
		private TopicEnd(Topic topic, Direction direction) {
			this.direction = direction;
			this.topic = topic;
		}

		public Direction getDirection() {
			return direction;
		}

		public Topic getTopic() {
			return topic;
		}

		public void setTopic(Topic topic) {
			this.topic = topic;
		}

		public VerbEnum getVerb() {
			return this.topic.getVerb();
		}

		public String getNoun() {
			return this.topic.getNoun();
		}
		
		
		public boolean isIn() {
			return this.direction == Direction.in;
		}

		public boolean isOut() {
			return this.direction == Direction.out;
		}

		@Override
		public String toString() {
			return "TopicEnd [topic=" + topic + ", direction=" + direction + "]";
		}



	}
	
	private Topic(VerbEnum verb, String noun) {
		this.verb = verb;
		this.noun = noun;
		
	}
	
	
	public static TopicEnd in(VerbEnum verb, NounEnum noun) {
		return new TopicEnd(verb, noun, Direction.in);
	}
	
	public static TopicEnd out(VerbEnum verb, NounEnum noun) {
		return new TopicEnd(verb, noun, Direction.out);
	}	
	
	public static TopicEnd in(VerbEnum verb, String noun) {
		return new TopicEnd(verb, noun, Direction.in);
	}
	
	public static TopicEnd out(VerbEnum verb, String noun) {
		return new TopicEnd(verb, noun, Direction.out);
	}
	
	public TopicEnd out() {
		return new TopicEnd(this, Direction.out);
	}	
	
	
	public TopicEnd in() {
		return new TopicEnd(this, Direction.in);
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
	
//	public static Topic parse(String name) {
//		int pos = name.indexOf('_');
//		if (pos < 0)
//			return null;
//		
//		VerbEnum verb = Enum.valueOf(VerbEnum.class, name.substring(0, pos));
//		String noun = name.substring(pos + 1);
//		
//		return new Topic(verb, noun);
//	}

	@Override
	public String toString() {
		return "Topic [verb=" + verb + ", noun=" + noun + "]";
	}


}
