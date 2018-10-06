import java.io.*;
import java.util.Random;

/**
 * 生成随机数, 获取待排序数组
 */
public class Utils {

    public static final int ELEMENT_COUNT = 1000;
    public static final String NO_SORT = "no_sort";
    public static final String SORT = "sort";

    public static void createRandomElement() {
        DataOutputStream outputStream = null;
        File file = null;
        try {
            file = new File(NO_SORT);
            if (file.exists()) {
                file.delete();
            }
            outputStream = new DataOutputStream(new FileOutputStream(NO_SORT, true));
            Random random = new Random(System.currentTimeMillis());
            for (int i = 0; i < ELEMENT_COUNT; i++) {
                int temp = random.nextInt(1000);
                outputStream.writeInt(temp);
                outputStream.flush();
            }
        } catch (java.io.IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (outputStream != null)
                    outputStream.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static int[] getRandomElement(String fileName) {
        DataInputStream inputStream = null;
        int[] result = new int[ELEMENT_COUNT];
        try {
            inputStream = new DataInputStream(new FileInputStream(fileName));
            for (int i = 0; i < ELEMENT_COUNT; i++) {
                int temp = inputStream.readInt();
                result[i] = temp;
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (inputStream != null)
                    inputStream.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return result;
    }

    public static void writeSortResult(int[] result) {
        DataOutputStream outputStream = null;
        try {
            File file = new File(SORT);
            if (file.exists())
                file.delete();
            outputStream = new DataOutputStream(new FileOutputStream(SORT, true));
            for (int i = 0; i < result.length; i++) {
                outputStream.writeInt(result[i]);
            }

        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                outputStream.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static void printSortResult(int[] data) {
        if (data != null) {
            for (int i = 0; i < data.length; i++)
                System.out.println(data[i]);
            return;
        }
        File file = new File(SORT);
        if (!file.exists())
            return;
        int[] result = getRandomElement(SORT);
        for (int i = 0; i < result.length; i++)
            System.out.println(result[i]);
    }

    public static void exch(int[] data, int i, int j) {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    public static int less(int i, int j) {
        return j - i;
    }

    // test
    public static void main(String[] args) {
        createRandomElement();
        int[] result = getRandomElement(NO_SORT);
        writeSortResult(result);
        int temp[] = getRandomElement(SORT);
        for (int i = 0; i < temp.length; i++) {
            System.out.println(temp[i]);
        }
    }
}
