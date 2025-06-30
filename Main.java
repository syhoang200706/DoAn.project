public class Main {

    public static void main(String[] args) {
        SinhVienIT sv1 = new SinhVienIT("Hoang Van Sy", "12A13", 45,"Cong nghe thong tin");
        sv1.hienThi();
    }
}

class SinhVien{
    private String ten;
    private String lop;
    private int soLuong;

    public SinhVien(String ten,String lop,int soLuong){
        this.ten=ten;
        this.lop=lop;
        this.soLuong=soLuong;
    }

    public String getTen() {
        return ten;
    }

    public void setTen(String ten) {
        this.ten = ten;
    }

    public String getLop() {
        return lop;
    }

    public void setLop(String lop) {
        this.lop = lop;
    }

    public int getSoLuong() {
        return soLuong;
    }

    public void setSoLuong(int soLuong) {
        this.soLuong = soLuong;
    }
    

    public void hienThi(){
        System.out.println("Ten :"+ten);
        System.out.println("Lop :"+lop);
        System.out.println("So Luong :"+soLuong);
    }
}

class SinhVienIT extends SinhVien{
    private String chuyenNganh;

    public SinhVienIT(String ten,String lop,int soLuong,String chuyenNganh){
        super(ten, lop, soLuong);
        this.chuyenNganh=chuyenNganh;
    }

    public String getChuyenNganh() {
        return chuyenNganh;
    }

    public void setChuyenNganh(String chuyenNganh) {
        this.chuyenNganh = chuyenNganh;
    }
    
    public void hienThi(){
        super.hienThi();
        System.out.println("Chuyen Nghanh :"+chuyenNganh);
        
    }
}