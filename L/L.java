import java.util.Scanner;
public class L {

    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        for(int i = 0; i < n; i++){
            long x = s.nextLong();
            System.out.println(rec(x));
        }
        return;
    }

    public static String rec(long x){
        if(x == 1){
            return "2";
        }else if (x % 2 == 1){
            return ("(2*" + rec(x-1) + ")");
        }else{
            return ("(" + rec(x/2) + ")^2");
        }
    }
    
}