package test;


import source.Stopwatch;
import source.StopwatchCPU;

public class Demo {
    public static void main(String[] args) {
        Stopwatch stopwatch = new Stopwatch();
        StopwatchCPU stopwatchCPU = new StopwatchCPU();
        int data[] = {40, -10, -30, 30, -20, 100, 80, -90};
        int num = 1000;
        int count = 0;
        for (int i = 0; i < num; i++)
            for (int j = 0; j < num; j++)
                for (int k = 0; k < num; k++) {
                    if (data[i % data.length] + data[j % data.length] + data[k % data.length] == 0) {
                        count++;
                    }
                }
        double time = stopwatch.elapsedTime();
        double cputTime = stopwatchCPU.elapsedTime();
        System.out.println(time + " ; " + cputTime);
    }
}
