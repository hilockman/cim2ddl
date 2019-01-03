package com.znd.bus.server;

public class Topic {

	private VerbEnum verb;
	private String noun;
	
	private String name;
	
	public static VerbTypeEnum type(VerbEnum verb) {
		switch (verb) {
		case get:
			return VerbTypeEnum.Request;
		case create: 
		case change: 
		case delete: 
		case close: 
		case cancel: 
		case execute:
			return VerbTypeEnum.Tansaction;
		case reply:
			return VerbTypeEnum.Response;
		case created:
		case changed:
		case deleted:
		case closed:
		case canceled:
		case executed:
			return VerbTypeEnum.Event;
		default:
			return VerbTypeEnum.Unknown;
		}
	}
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
	
	public Topic(VerbEnum verb, String noun) {
		this.verb = verb;
		this.noun = noun;
		this.name = formName(verb, noun);
		
	}
	
	
	public static TopicEnd in(VerbEnum verb, NounEnum noun) {
		return new TopicEnd(verb, noun, Direction.in);
	}
	
	public static TopicEnd out(VerbEnum verb, NounEnum noun) {
		return new TopicEnd(verb, noun, Direction.out);
	}	
	
	public static TopicEnd in_and_out(VerbEnum verb, NounEnum noun) {
		return new TopicEnd(verb, noun, Direction.in_and_out);
	}
	
	public static TopicEnd in_and_out(VerbEnum verb, String noun) {
		return new TopicEnd(verb, noun, Direction.in_and_out);
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
		return name;
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

	@Override
	public String toString() {
		return "Topic [verb=" + verb + ", noun=" + noun + "]";
	}


}
