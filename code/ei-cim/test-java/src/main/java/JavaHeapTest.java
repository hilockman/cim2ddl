public class JavaHeapTest {
    public final static int OUTOFMEMORY = 2000000000;
    
    private String oom;

    private int length;
    
    StringBuffer tempOOM = new StringBuffer();

    public JavaHeapTest(int leng) {
        this.length = leng;
       
        int i = 0;
        while (i < leng) {
            i++;
            try {
                tempOOM.append("a");
            } catch (OutOfMemoryError e) {
               e.printStackTrace();
               break;
            }
        }
        this.oom = tempOOM.toString();

		while(true) {
			try {
			Thread.sleep(10);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
    }

    public String getOom() {
        return oom;
    }

    public int getLength() {
        return length;
    }

    public static void main(String[] args) {
        JavaHeapTest javaHeapTest = new JavaHeapTest(OUTOFMEMORY);
        System.out.println(javaHeapTest.getOom().length());
    }

}