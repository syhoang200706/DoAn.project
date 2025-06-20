#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

typedef string date;
typedef string Time;

int TimeToMinutes(const string& timeStr) {
    int h, m;
    if (sscanf(timeStr.c_str(), "%d:%d", &h, &m) != 2) return 0;
    return h * 60 + m;
}

int DateToDays(const string& dateStr) {
    int y, m, d;
    if (sscanf(dateStr.c_str(), "%d-%d-%d", &y, &m, &d) != 3) return 0;
    return y * 365 + m * 30 + d;
}

class sach {
protected:
    string Masach, Tensach, Chude, Tacgia, nhaxuatban;
    date ngayxuatban;
    int sotrang, sobanluu;
    bool trangthai;

public:
    sach() {}
    sach(string ma, string ten, string chude, string tacgia, string nxb, date ngay, int trang, int ban, bool tt)
        : Masach(ma), Tensach(ten), Chude(chude), Tacgia(tacgia), nhaxuatban(nxb),
          ngayxuatban(ngay), sotrang(trang), sobanluu(ban), trangthai(tt) {}
    virtual ~sach() {}

    virtual void Nhapthongtin(ifstream& r) {
        string temp;
        getline(r, Masach, '/');
        getline(r, Tensach, '/');
        getline(r, Chude, '/');
        getline(r, Tacgia, '/');
        getline(r, nhaxuatban, '/');
        getline(r, ngayxuatban, '/');
        getline(r, temp, '/');
        sotrang = stoi(temp);
        getline(r, temp, '/');
        sobanluu = stoi(temp);
        getline(r, temp);
        trangthai = (temp == "1");
    }

    virtual void Hienthi() {
        cout << "| " << setw(10) << left << Masach
             << "| " << setw(35) << left << Tensach
             << "| " << setw(15) << left << Chude
             << "| " << setw(25) << left << Tacgia
             << "| " << setw(15) << left << nhaxuatban
             << "| " << setw(12) << left << ngayxuatban
             << "| " << setw(8) << left << sotrang
             << "| " << setw(10) << left << sobanluu
             << "| " << setw(20) << left << (trangthai ? "Co the muon ve" : "Muon doc tai cho")
             << "|\n";
    }

    virtual void HienThiFile(ofstream& out) {
        out << "| " << setw(10) << left << Masach
            << "| " << setw(35) << left << Tensach
            << "| " << setw(15) << left << Chude
            << "| " << setw(25) << left << Tacgia
            << "| " << setw(15) << left << nhaxuatban
            << "| " << setw(12) << left << ngayxuatban
            << "| " << setw(8) << left << sotrang
            << "| " << setw(10) << left << sobanluu
            << "| " << setw(20) << left << (trangthai ? "Co the muon ve" : "Muon doc tai cho")
            << "|\n";
    }

    string getmasach() const { return Masach; }
    string gettensach() const { return Tensach; }
    string getChude() const { return Chude; }
    string gettacgia() const { return Tacgia; }
    string getnhaxuatban() const { return nhaxuatban; }
    date getngayxuatban() const { return ngayxuatban; }
    int getsotrang() const { return sotrang; }
    int getsobanluu() const { return sobanluu; }
    bool gettrangthai() const { return trangthai; }

    void NhapTuBanPhim() {
        cout << "Nhap ma sach: "; getline(cin, Masach);
        cout << "Nhap ten sach: "; getline(cin, Tensach);
        cout << "Nhap chu de: "; getline(cin, Chude);
        cout << "Nhap tac gia: "; getline(cin, Tacgia);
        cout << "Nhap nha xuat ban: "; getline(cin, nhaxuatban);
        cout << "Nhap ngay xuat ban (YYYY-MM-DD): "; getline(cin, ngayxuatban);
        cout << "Nhap so trang: "; 
        while (!(cin >> sotrang) || sotrang < 0) {
            cout << "So trang khong hop le, nhap lai: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cin.ignore();
        cout << "Nhap so ban luu: "; 
        while (!(cin >> sobanluu) || sobanluu < 0) {
            cout << "So ban luu khong hop le, nhap lai: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cin.ignore();
        cout << "Trang thai (1: muon ve, 0: doc tai cho): "; 
        int tt;
        while (!(cin >> tt) || (tt != 0 && tt != 1)) {
            cout << "Trang thai khong hop le (0 hoac 1), nhap lai: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cin.ignore();
        trangthai = (tt == 1);
    }

    bool MuonSach() {
        if (!trangthai) {
            cout << "Sach chi co the doc tai cho!\n";
            return false;
        }
        if (sobanluu <= 0) {
            cout << "Khong con ban luu!\n";
            return false;
        }
        sobanluu--;
        cout << "Muon sach thanh cong!\n";
        return true;
    }

    void TraSach() {
        sobanluu++;
    }
};

class SachMuonDoc : public sach {
private:
    Time GioMuon, GioTra;
public:
    void NhapThongTin() {
        cout << "Nhap gio muon (HH:MM): "; getline(cin, GioMuon);
        cout << "Nhap gio tra (HH:MM): "; getline(cin, GioTra);
    }

    void HienThiThongTin() {
        cout << "Gio muon: " << GioMuon << "\n";
        cout << "Gio tra: " << GioTra << "\n";
    }

    void HienThiTraSach() {
        cout << "Gio tra: " << GioTra << ", Trang thai: " << TrangThai() << "\n";
    }

    int TinhThoiGianDoc() {
        return TimeToMinutes(GioTra) - TimeToMinutes(GioMuon);
    }

    string TrangThai() {
        return TinhThoiGianDoc() > 120 ? "Qua gio quy dinh" : "Trong gio quy dinh";
    }
    string getGioMuon() const { return GioMuon; }
	string getGioTra()  const { return GioTra; }
};

class SachMuonVe : public sach {
private:
    date NgayMuon, NgayHenTra, NgayTra;
public:
    void NhapThongTin() {
        cout << "Nhap ngay muon (YYYY-MM-DD): "; getline(cin, NgayMuon);
        cout << "Nhap ngay hen tra (YYYY-MM-DD): "; getline(cin, NgayHenTra);
    }

    void HienThiThongTin() {
        cout << "Ngay muon: " << NgayMuon << ", Ngay hen tra: " << NgayHenTra << "\n";
    }

    void HienThiTraSach() {
        cout << "Nhap ngay tra (YYYY-MM-DD): "; getline(cin, NgayTra);
        if (TinhThoiGianTreHan() > 0)
            cout << "Ngay tra: " << NgayTra << " => Tre han " << TinhThoiGianTreHan() << " ngay\n";
        else
            cout << "Ngay tra: " << NgayTra << " => Tra dung han\n";
    }

    int TinhThoiGianTreHan() {
        return DateToDays(NgayTra) - DateToDays(NgayHenTra);
    }

    date getNgayMuon() const { return NgayMuon; }
    date getNgayHenTra() const { return NgayHenTra; }
    date getNgayTra() const { return NgayTra; }

};

class Thuvien {
public:
    vector<sach*> dsSach;
    vector<SachMuonDoc> dsMuonDoc;
	vector<SachMuonVe> dsMuonVe;
    int soluong;

    Thuvien() : soluong(0) {}

    ~Thuvien() {
        for (auto s : dsSach) delete s;
        dsSach.clear();
    }

    void NhapDuLieuTuFile() {
        ifstream read("input.txt");
        if (!read.is_open()) {
            cout << "Khong the mo file input.txt!\n";
            return;
        }
        while (read.peek() != EOF) {
            sach* s = new sach();
            s->Nhapthongtin(read);
            if (!s->gettensach().empty()) {
                dsSach.push_back(s);
                soluong++;
            } else {
                delete s;
            }
        }
        read.close();
    }

    void Hienthi() {
        cout << "\n=================================================================== DANH SACH SACH ================================================================================\n";
        cout << "+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
        cout << "| " << setw(10) << left << "Ma sach"
             << "| " << setw(35) << left << "Ten sach"
             << "| " << setw(15) << left << "Chu de"
             << "| " << setw(25) << left << "Tac gia"
             << "| " << setw(15) << left << "NXB"
             << "| " << setw(12) << left << "Ngay XB"
             << "| " << setw(8) << left << "Trang"
             << "| " << setw(10) << left << "So ban"
             << "| " << setw(20) << left << "Trang thai"
             << "|\n";
        cout << "+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
        for (size_t i = 0; i < dsSach.size(); i++) {
            dsSach[i]->Hienthi();
        }
        cout << "+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
    }

    void HienThiFile() {
        ofstream write("output.txt");
        if (write.is_open()) {
            write << "\n=================================================================== DANH SACH SACH ================================================================================\n";
            write << "+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
            write << "| " << setw(10) << left << "Ma sach"
                  << "| " << setw(35) << left << "Ten sach"
                  << "| " << setw(15) << left << "Chu de"
                  << "| " << setw(25) << left << "Tac gia"
                  << "| " << setw(15) << left << "NXB"
                  << "| " << setw(12) << left << "Ngay XB"
                  << "| " << setw(8) << left << "Trang"
                  << "| " << setw(10) << left << "So ban"
                  << "| " << setw(20) << left << "Trang thai"
                  << "|\n";
            write << "+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
            for (size_t i = 0; i < dsSach.size(); i++) {
                dsSach[i]->HienThiFile(write);
            }
            write << "+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
            write.close();
        } else {
            cout << "Khong mo duoc file output.txt de ghi!\n";
        }
    }
    void HienThiSachMuonDoc() {
    ofstream out("output.txt", ios::app);
    cout << "\n=============================== DANH SACH SACH MUON DOC TAI CHO ==================================\n";
    out << "\n=============================== DANH SACH SACH MUON DOC TAI CHO ==================================\n";

    if (dsMuonDoc.empty()) {
        cout << "Khong co sach nao dang doc tai cho.\n";
        out << "Khong co sach nao dang doc tai cho.\n";
    } else {
        cout << "+-----+-----------+-------------------------------------+---------------+--------------------------+-----------+-----------+--------------------------+\n";
         out << "+-----+-----------+-------------------------------------+---------------+--------------------------+-----------+-----------+--------------------------+\n";
        cout << "| " << setw(4) << left << "STT"
             << "| " << setw(10) << left << "Ma sach"
             << "| " << setw(35) << left << "Ten sach"
             << "| " << setw(15) << left << "Chu de"
             << "| " << setw(25) << left << "Tac gia"
             << "| " << setw(10) << left << "Gio muon"
             << "| " << setw(10) << left << "Gio tra"
             << "| " << setw(25) << left << "Trang thai doc"
             << "|\n";
        out  << "| " << setw(4) << left << "STT"
             << "| " << setw(10) << left << "Ma sach"
             << "| " << setw(35) << left << "Ten sach"
             << "| " << setw(15) << left << "Chu de"
             << "| " << setw(25) << left << "Tac gia"
             << "| " << setw(10) << left << "Gio muon"
             << "| " << setw(10) << left << "Gio tra"
             << "| " << setw(25) << left << "Trang thai doc"
             << "|\n";

            cout << "+-----+-----------+-------------------------------------+---------------+--------------------------+-----------+-----------+--------------------------+\n";
             out << "+-----+-----------+-------------------------------------+---------------+--------------------------+-----------+-----------+--------------------------+\n";
             
        for (size_t i = 0; i < dsMuonDoc.size(); ++i) {
            cout << "| " << setw(4) << left << i + 1
                 << "| " << setw(10) << left << dsMuonDoc[i].getmasach()
                 << "| " << setw(35) << left << dsMuonDoc[i].gettensach()
                 << "| " << setw(15) << left << dsMuonDoc[i].getChude()
                 << "| " << setw(25) << left << dsMuonDoc[i].gettacgia()
                 << "| " << setw(10) << left << dsMuonDoc[i].getGioMuon()
                 << "| " << setw(10) << left << dsMuonDoc[i].getGioTra()
                 << "| " << setw(25) << left << dsMuonDoc[i].TrangThai()
                 << "|\n";

            out << "| " << setw(4) << left << i + 1
                << "| " << setw(10) << left << dsMuonDoc[i].getmasach()
                << "| " << setw(35) << left << dsMuonDoc[i].gettensach()
                << "| " << setw(15) << left << dsMuonDoc[i].getChude()
                << "| " << setw(25) << left << dsMuonDoc[i].gettacgia()
                << "| " << setw(10) << left << dsMuonDoc[i].getGioMuon()
                << "| " << setw(10) << left << dsMuonDoc[i].getGioTra()
                << "| " << setw(25) << left << dsMuonDoc[i].TrangThai()
                << "|\n";
        }
        cout << "+-----+-----------+------------------------------------+----------------+--------------------------+-----------+-----------+--------------------------+\n";
         out << "+-----+-----------+------------------------------------+----------------+--------------------------+-----------+-----------+--------------------------+\n";

    }

    out.close();
}

    void HienThiSachMuonVe() {
    ofstream out("output.txt", ios::app);
    cout << "\n================================== DANH SACH SACH MUON VE =================================\n";
    out << "\n================================== DANH SACH SACH MUON VE =================================\n";

    if (dsMuonVe.empty()) {
        cout << "Khong co sach nao dang muon ve.\n";
        out << "Khong co sach nao dang muon ve.\n";
    } else {
        cout << "+-----+-----------+------------------------------------+----------------+--------------------------+-------------+-------------+\n";
        out << "+-----+-----------+------------------------------------+----------------+--------------------------+-------------+-------------+\n";
        cout << "| " << setw(4) << left << "STT"
             << "| " << setw(10) << left << "Ma sach"
             << "| " << setw(35) << left << "Ten sach"
             << "| " << setw(15) << left << "Chu de"
             << "| " << setw(25) << left << "Tac gia"
             << "| " << setw(12) << left << "Ngay muon"
             << "| " << setw(12) << left << "Ngay hen tra"
             << "|\n";

        out << "| " << setw(4) << left << "STT"
            << "| " << setw(10) << left << "Ma sach"
            << "| " << setw(35) << left << "Ten sach"
            << "| " << setw(15) << left << "Chu de"
            << "| " << setw(25) << left << "Tac gia"
            << "| " << setw(12) << left << "Ngay muon"
            << "| " << setw(12) << left << "Ngay hen tra"
            << "|\n";

        cout << "+-----+-----------+------------------------------------+----------------+--------------------------+-------------+-------------+\n";
        out << "+-----+-----------+------------------------------------+----------------+--------------------------+-------------+-------------+\n";

        for (size_t i = 0; i < dsMuonVe.size(); ++i) {
            cout << "| " << setw(4) << left << i + 1
                 << "| " << setw(10) << left << dsMuonVe[i].getmasach()
                 << "| " << setw(35) << left << dsMuonVe[i].gettensach()
                 << "| " << setw(15) << left << dsMuonVe[i].getChude()
                 << "| " << setw(25) << left << dsMuonVe[i].gettacgia()
                 << "| " << setw(12) << left << dsMuonVe[i].getNgayMuon()
                 << "| " << setw(12) << left << dsMuonVe[i].getNgayHenTra()
                 << "|\n";

            out << "| " << setw(4) << left << i + 1
                << "| " << setw(10) << left << dsMuonVe[i].getmasach()
                << "| " << setw(35) << left << dsMuonVe[i].gettensach()
                << "| " << setw(15) << left << dsMuonVe[i].getChude()
                << "| " << setw(25) << left << dsMuonVe[i].gettacgia()
                << "| " << setw(12) << left << dsMuonVe[i].getNgayMuon()
                << "| " << setw(12) << left << dsMuonVe[i].getNgayHenTra()
                << "|\n";
        }

        cout << "+-----+-----------+------------------------------------+----------------+--------------------------+-------------+-------------+\n";
        out << "+-----+-----------+------------------------------------+----------------+--------------------------+-------------+-------------+\n";

    }

    out.close();
}


    void TimKiemTen(string& ten) {
        ofstream out("output.txt");
        bool found = false;
        out << "\n============================================== KET QUA TIM KIEM THEO TEN SACH: \"" << ten << "\" ==================================================\n";
        out << "+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
        out << "| " << setw(10) << left << "Ma sach"
            << "| " << setw(35) << left << "Ten sach"
            << "| " << setw(15) << left << "Chu de"
            << "| " << setw(25) << left << "Tac gia"
            << "| " << setw(15) << left << "NXB"
            << "| " << setw(12) << left << "Ngay XB"
            << "| " << setw(8) << left << "Trang"
            << "| " << setw(10) << left << "So ban"
            << "| " << setw(20) << left << "Trang thai"
            << "|\n";
        out << "+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
        for (size_t i = 0; i < dsSach.size(); i++) {
            if (dsSach[i]->gettensach().find(ten) != string::npos) {
                dsSach[i]->HienThiFile(out);
                found = true;
            }
        }
        out << "+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
        if (!found) {
            out << "Khong tim thay sach co chua \"" << ten << "\" trong thu vien.\n";
        }
        out.close();
    }

    void TimKiemTacGia(string& tacgia) {
        ofstream out("output.txt");
        bool found = false;
        out << "\n============================================== KET QUA TIM KIEM THEO TEN TAC GIA: \"" << tacgia << "\" ===============================================\n";
        out << "+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
        out << "| " << setw(10) << left << "Ma sach"
            << "| " << setw(35) << left << "Ten sach"
            << "| " << setw(15) << left << "Chu de"
            << "| " << setw(25) << left << "Tac gia"
            << "| " << setw(15) << "NXB"
            << "| " << setw(12) << left << "Ngay XB"
            << "| " << setw(8) << left << "Trang"
            << "| " << setw(10) << left << "So ban"
            << "| " << setw(20) << left << "Trang thai"
            << "|\n";
        out << "+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
        for (size_t i = 0; i < dsSach.size(); i++) {
            if (dsSach[i]->gettacgia().find(tacgia) != string::npos) {
                dsSach[i]->HienThiFile(out);
                found = true;
            }
        }
        out << "+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
        if (!found) {
            out << "Khong tim thay sach co chua \"" << tacgia << "\" trong thu vien.\n";
        }
        out.close();
    }

    void TimKiemChuDe(string& chude) {
        ofstream out("output.txt");
        bool found = false;
        out << "\n============================================== KET QUA TIM KIEM THEO CHU DE: \"" << chude << "\" ============================================================\n";
        out << "+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
        out << "| " << setw(10) << left << "Ma sach"
            << "| " << setw(35) << left << "Ten sach"
            << "| " << setw(15) << left << "Chu de"
            << "| " << setw(25) << left << "Tac gia"
            << "| " << setw(15) << left << "NXB"
            << "| " << setw(12) << left << "Ngay XB"
            << "| " << setw(8) << left << "Trang"
            << "| " << setw(10) << left << "So ban"
            << "| " << setw(20) << left << "Trang thai"
            << "|\n";
        out << "+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
        for (size_t i = 0; i < dsSach.size(); i++) {
            if (dsSach[i]->getChude().find(chude) != string::npos) {
                dsSach[i]->HienThiFile(out);
                found = true;
            }
        }
        out << "+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
        if (!found) {
            out << "Khong tim thay sach co chua \"" << chude << "\" trong thu vien.\n";
        }
        out.close();
    }

    void ThemSach() {
        sach* s = new sach();
        s->NhapTuBanPhim();
        dsSach.push_back(s);
        soluong++;
        ofstream out("input.txt", ios::app);
        if (out.is_open()) {
            out << s->getmasach() << "/"
                << s->gettensach() << "/"
                << s->getChude() << "/"
                << s->gettacgia() << "/"
                << s->getnhaxuatban() << "/"
                << s->getngayxuatban() << "/"
                << s->getsotrang() << "/"
                << s->getsobanluu() << "/"
                << (s->gettrangthai() ? "1" : "0") << "\n";
            out.close();
        } else {
            cout << "Khong mo duoc file input.txt de ghi!\n";
        }
        cout << "Da them sach thanh cong!\n";
    }

    void MuonSach(const string& ten) {
        for (size_t i = 0; i < dsSach.size(); i++) {
            if (dsSach[i]->gettensach().find(ten) != string::npos) {
                string loai;
                cout << "Muon doc tai cho/ Muon ve (D/V): "; getline(cin, loai);
                if (loai == "D" || loai == "d") {
                    if (dsSach[i]->gettrangthai()) {
                        cout << "Sach nay chi co the muon ve, khong phai sach muon doc tai cho!\n";
                        return;
                    }
                    SachMuonDoc doc;
                    *static_cast<sach*>(&doc) = *dsSach[i];
                    doc.NhapThongTin();
                    doc.HienThiThongTin();
                    dsMuonDoc.push_back(doc);
                    cout << "Muon sach \"" << ten << "\" de doc tai cho thanh cong.\n";
                } else if (loai == "V" || loai == "v") {
                    if (!dsSach[i]->gettrangthai()) {
                        cout << "Sach nay chi co the doc tai cho, khong the muon ve!\n";
                        return;
                    }
                    if (dsSach[i]->getsobanluu() <= 0) {
                        cout << "Khong con ban luu!\n";
                        return;
                    }
                    dsSach[i]->MuonSach();
                    SachMuonVe ve;
                    *static_cast<sach*>(&ve) = *dsSach[i];
                    ve.NhapThongTin();
                    ve.HienThiThongTin();
                    dsMuonVe.push_back(ve);
                    cout << "Muon sach \"" << ten << "\" ve thanh cong.\n";
                } else {
                    cout << "Lua chon khong hop le.\n";
                }
                return;
            }
        }
        cout << "Khong tim thay sach \"" << ten << "\" trong thu vien.\n";
    }

    void TraSach(const string& ten) {
    ofstream write("output.txt", ios::app);
    if (!write.is_open()) {
        cout << "Khong mo duoc file output.txt de ghi!\n";
        return;
    }

    write << "\n========================================================================= KET QUA TRA SACH =================================================================================\n";
    write << "+-----+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
    write << "| " << setw(4) << left << "STT"
          << "| " << setw(10) << left << "Ma sach"
          << "| " << setw(35) << left << "Ten sach"
          << "| " << setw(15) << left << "Chu de"
          << "| " << setw(25) << left << "Tac gia"
          << "| " << setw(15) << left << "NXB"
          << "| " << setw(12) << left << "Ngay XB"
          << "| " << setw(8) << left << "Trang"
          << "| " << setw(10) << left << "So ban"
          << "| " << setw(20) << left << "Trang thai"
          << "|\n";
   write << "+-----+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";

    string loai;
    cout << "Tra sach muon doc tai cho/ Muon ve (D/V): ";
    getline(cin, loai);

    if (loai == "D" || loai == "d") {
        bool found = false;
        for (size_t i = 0; i < dsMuonDoc.size(); ++i) {
            if (dsMuonDoc[i].gettensach() == ten) {
                found = true;
                dsMuonDoc[i].HienThiTraSach();

                // Ghi vÃ o file
                write << "| " << setw(4) << left << (i + 1); 
                dsMuonDoc[i].HienThiFile(write);
                write << "+-----+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
                write << " Ghi chu: Da tra sach muon doc tai cho: " << ten
                      << "   -    Gio tra: " << dsMuonDoc[i].TrangThai() << " \n";

                // XÃ³a khá»i danh sÃ¡ch mÆ°á»£n Ä‘á»c
                dsMuonDoc.erase(dsMuonDoc.begin() + i);
                cout << "Tra sach \"" << ten << "\" thanh cong.\n";
                write.close();
                return;
            }
        }
        if (!found) {
            cout << "Khong tim thay sach \"" << ten << "\" trong danh sach muon doc tai cho.\n";
            write << " Khong tim thay sach \"" << ten << "\" trong danh sach muon doc tai cho \n";
        }

    } else if (loai == "V" || loai == "v") {
        bool found = false;
        for (size_t i = 0; i < dsMuonVe.size(); ++i) {
            if (dsMuonVe[i].gettensach() == ten) {
                found = true;
                dsMuonVe[i].HienThiTraSach();
                write << "| " << setw(4) << left << (i + 1);
                dsMuonVe[i].HienThiFile(write);
                write << "+-----+-----------+------------------------------------+----------------+--------------------------+----------------+-------------+---------+-----------+---------------------+\n";
                write << " Ghi chu: Da tra sach muon ve: " << ten;
                
                if (dsMuonVe[i].TinhThoiGianTreHan() > 0) {
                    write << ", Tra tre han"  << "|";
                    cout << "Sach tra tre han.\n";
                } else {
                    write << ", Tra dung han " << "|";
                    cout << "Sach tra dung han.\n";
                }

                dsMuonVe.erase(dsMuonVe.begin() + i);
                write.close();
                return;
            }
        }
        if (!found) {
            cout << "Khong tim thay sach \"" << ten << "\" trong danh sach muon ve.\n";
            write << "| Khong tim thay sach \"" << ten << "\" trong danh sach muon ve |";
        }

    } else {
        cout << "Lua chon khong hop le.\n";
        write << "| Ghi chu: Lua chon tra sach khong hop le cho sach \"" << ten << " |";
    }
    write.close();
}

};

void Menu() {
    Thuvien Tv;
    Tv.NhapDuLieuTuFile();
    int n;
    do {
        cout << "\n==================== Menu ====================\n";
        cout << "0. Thoat chuong trinh.\n";
        cout << "1. Hien thi sach.\n";
        cout << "2. Tim kiem sach.\n";
        cout << "3. Muon sach.\n";
        cout << "4. Tra sach.\n";
        cout << "5. Them sach vao thu vien.\n";
        cout << "==============================================\n";
        cout << "Nhap lua chon so: ";
        while (!(cin >> n)) {
            cout << "Lua chon khong hop le, nhap lai: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cin.ignore();

        switch (n) {
            case 0:
                cout << "Thoat chuong trinh thanh cong.\n";
                break;

            case 1: {
                cout << "1.1 Hien thi sach trong man hinh.\n";
                cout << "1.2 Hien thi tat ca sach trong file.\n";
                cout << "1.3 Hien thi danh sach sach dang muon doc.\n";
                cout << "1.4 Hien thi danh sach sach dang muon ve.\n";
                cout << "\nNhap lua chon so: ";
                int chon1;
                while (!(cin >> chon1)) {
                    cout << "Lua chon khong hop le, nhap lai: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                cin.ignore();
                switch (chon1) {
                    case 1:{
                    	Tv.Hienthi();
						break;
					}
                        
                    case 2:{
                    	Tv.HienThiFile();
                        cout << "Yeu cau cua ban da thuc hien trong file output.txt\n";
						break;
					}
                        
                    case 3:{
                    	Tv.HienThiSachMuonDoc();                       
                        cout << "Yeu cau cua ban da thuc hien trong file output.txt\n";
                        break;
					}
                        
                    case 4:{
                    	Tv.HienThiSachMuonVe();
                    	cout << "Yeu cau cua ban da thuc hien trong file output.txt\n";
						break;
					}
                    	                        
                    default:
                        cout << "Lua chon khong hop le.\n";
                        break;
                }
                break;
            }

            case 2: {
                cout << "2.1 Tim kiem sach theo ten sach.\n";
                cout << "2.2 Tim kiem sach theo ten tac gia.\n";
                cout << "2.3 Tim kiem sach theo chu de.\n";
                cout << "\nNhap lua chon so: ";
                int chon2;
                while (!(cin >> chon2)) {
                    cout << "Lua chon khong hop le, nhap lai: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                cin.ignore();
                switch (chon2) {
                    case 1: {
                        string tenSach;
                        cout << "Nhap ten sach can tim: ";
                        getline(cin, tenSach);
                        Tv.TimKiemTen(tenSach);
                        cout << "Yeu cau cua ban da thuc hien trong file output.txt\n";
                        break;
                    }
                    case 2: {
                        string tenTacGia;
                        cout << "Nhap ten tac gia can tim: ";
                        getline(cin, tenTacGia);
                        Tv.TimKiemTacGia(tenTacGia);
                        cout << "Yeu cau cua ban da thuc hien trong file output.txt\n";
                        break;
                    }
                    case 3: {
                        string chuDe;
                        cout << "Nhap chu de can tim: ";
                        getline(cin, chuDe);
                        Tv.TimKiemChuDe(chuDe);
                        cout << "Yeu cau cua ban da thuc hien trong file output.txt\n";
                        break;
                    }
                    default:
                        cout << "Lua chon khong hop le.\n";
                        break;
                }
                break;
            }

            case 3: {
                int soLuong;
                cout << "Nhap so sach muon muon: ";
                while (!(cin >> soLuong) || soLuong <= 0) {
                    cout << "So luong khong hop le, nhap lai: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                cin.ignore();
                for (int i = 0; i < soLuong; i++) {
                    string ten;
                    cout << "Nhap ten sach can muon " << i + 1 << ": ";
                    getline(cin, ten);
                    Tv.MuonSach(ten);
                }
                break;
            }

            case 4: {
                int soLuong;
                cout << "Nhap so sach can tra: ";
                while (!(cin >> soLuong) || soLuong <= 0) {
                    cout << "So luong khong hop le, nhap lai: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                cin.ignore();
                for (int i = 0; i < soLuong; i++) {
                    string ten;
                    cout << "Nhap ten sach can tra " << i + 1 << ": ";
                    getline(cin, ten);
                    Tv.TraSach(ten);
                }
                break;
            }

            case 5: {
                int soLuong;
                cout << "Nhap so sach can them: ";
                while (!(cin >> soLuong) || soLuong <= 0) {
                    cout << "So luong khong hop le, nhap lai: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                cin.ignore();
                for (int i = 0; i < soLuong; i++) {
                    Tv.ThemSach();
                }
                break;
            }

            default:
                cout << "Lua chon khong hop le.\n";
                break;
        }

    } while (n != 0);
}


int main() {
    Menu();
    return 0;
}