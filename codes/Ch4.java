public class Ch4 {
    public static void main(String[] args) {
        if (args.length > 0) {
            if (Integer.parseInt(args[0]) < 0)
                System.err.println(args[0] + " must be >= 0.");
            else {
                Sum sumObject = new Sum();
                int upper = Integer.parseInt(args[0]);
                Thread t = new Thread(new Summation(upper, sumObject));
                t.start();
                try {
                    t.join();
                    System.out.println("The sum of " + upper + " is " + sumObject.getSum());
                } catch (InterruptedException e) {

                }
            }

        } else {
            System.err.println("Usage: Summation <integer value> ");
        }
    }
}

class Sum {
    private int sum;

    public int getSum() {
        return this.sum;
    }

    public void setSum(int value) {
        this.sum = value;
    }
}

class Summation implements Runnable {
    private int upper;
    private Sum sumValue;

    public Summation(int upper, Sum sumValue) {
        this.upper = upper;
        this.sumValue = sumValue;
    }

    public void run() {
        int sum = 0;
        for (int i = 0; i <= upper; i++) {
            sum += i;

        }
        sumValue.setSum(sum);
    }
}