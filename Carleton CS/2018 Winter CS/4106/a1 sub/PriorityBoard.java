public class PriorityBoard{

		public PriorityBoard(Integer p, Integer[][] b) {
			this.priority = p;
			this.board = b;
		}

		public String myToString(Integer[][] b){

			String s = "";

			for (int i = 0; i < b.length; ++i){

			}

			return s;
		}

		public String toString(){
			return "Priority: " + priority.toString()
				 + ", Array: " + myToString(board);

		}

		Integer priority;
		Integer[][] board;
	}
