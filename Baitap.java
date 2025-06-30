import java.util.Scanner;

public class Baitap {

    public static void PTBN(){
        Scanner sc = new Scanner(System.in);

        System.out.print("Nhap a: ");
        double a = sc.nextDouble();
        System.out.print("Nhap b: ");
        double b = sc.nextDouble();

        if (a == 0) {
            if (b == 0) {
                System.out.println("Phuong trinh vo so nghiem.");
            } else {
                System.out.println("Phuog trinh vo nghiem.");
            }
        } else {
            double x = -b / a;
            System.out.println("Nghiem cua phuong trinh la x = " + x);
        }

        sc.close();
    }

    public static void PTBH(){
        Scanner sc = new Scanner(System.in);

        System.out.print("Nhap a: ");
        double a = sc.nextDouble();
        System.out.print("Nhap b: ");
        double b = sc.nextDouble();
        System.out.print("Nhap c: ");
        double c = sc.nextDouble();

        if (a == 0) {
            if (b == 0) {
                if (c == 0) {
                    System.out.println("Phuong trinh vo so nghiem.");
                } else {
                    System.out.println("Phuong trinh vo nghiem.");
                }
            } else {
                double x = -c / b;
                System.out.println("Phuong trinh bac nhat co nghiem: x = " + x);
            }
        } else {
            double delta = b * b - 4 * a * c;

            if (delta > 0) {
                double x1 = (-b + Math.sqrt(delta)) / (2 * a);
                double x2 = (-b - Math.sqrt(delta)) / (2 * a);
                System.out.println("Phuong trinh co 2 nghiem phan biet:");
                System.out.println("x1 = " + x1);
                System.out.println("x2 = " + x2);
            } else if (delta == 0) {
                double x = -b / (2 * a);
                System.out.println("Phuong trinh co nghiem kep: x = " + x);
            } else {
                System.out.println("Phuomg trinh vo nghiem");
            }
        }

        sc.close();
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("=============MeNu==============");
        System.out.println("+-----------------------------+");
        System.out.println("| 1.Giai phuong trinh bac nhat|");
        System.out.println("| 2.Giai phuong trinh bac hai |");
        System.out.println("| 3.Ket thuc chuong trinh     |");
        System.out.println("+-----------------------------+");

        System.out.println("Nhap lua chon cua ban");
        int x = sc.nextInt();
        switch (x) {
            case 1 :
                PTBN();
                break;
            case 2:
                PTBH();
                break;
            default:
            System.out.println("Ban da thoat chuong trinh ");
        }
    }
}
