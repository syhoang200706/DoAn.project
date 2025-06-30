public class QuanLyTinh {
     public static void main(String[] args) {
        Xa xuanLoc =new Xa("Ha Tinh", "38", 9999, "Binh Yen", 99999);
        xuanLoc.hienThi();

     }
}

class Tinh{
    private String tenTinh;
    private String maTinh;
    private int soLuongdan;

    public Tinh(String tenTinh,String maTinh,int soLuongdan){
        this.tenTinh = tenTinh;
        this.maTinh = maTinh;
        this.soLuongdan = soLuongdan;
    }

    public String getTenTinh() {
        return tenTinh;
    }

    public void setTenTinh(String tenTinh) {
        this.tenTinh = tenTinh;
    }

    public String getMaTinh() {
        return maTinh;
    }

    public void setMaTinh(String maTinh) {
        this.maTinh = maTinh;
    }

    public int getSoLuongdan() {
        return soLuongdan;
    }

    public void setSoLuongdan(int soLuongdan) {
        this.soLuongdan = soLuongdan;
    }

    public void hienThi(){
        System.out.println("Ten Tinh :"+tenTinh);
        System.out.println("Ma Tinh :"+maTinh);
        System.out.println("So Luong Dan :"+soLuongdan);
    }
}

class Xa extends Tinh{
    private String tenXa;
    private float dienTich;

    public Xa(String tenTinh,String maTinh,int soLuongdan,String tenXa,float dienTich){
        super(tenTinh, maTinh, soLuongdan);
        this.tenXa=tenXa;
        this.dienTich = dienTich;
    }

    public String getTenXa() {
        return tenXa;
    }

    public void setTenXa(String tenXa) {
        this.tenXa = tenXa;
    }

    public float getDienTich() {
        return dienTich;
    }

    public void setDienTich(float dienTich) {
        this.dienTich = dienTich;
    }
    public void hienThi(){
        super.hienThi();
        System.out.println("Ten Xa :"+tenXa);
        System.out.println("Dien Tich Xa :"+dienTich);
    }
}
