#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct SinhVien{
    int maSV;
    char* hoTen;
    float diemMH;
    struct SinhVien* next;
};
typedef struct SinhVien sv;


bool insertSinhVien(sv** head, sv sv){
    struct SinhVien* newNode = malloc(sizeof(sv));

    newNode->maSV = sv.maSV;
    newNode->hoTen = sv.hoTen;
    newNode->diemMH = sv.diemMH;
    newNode->next = *head;

    *head = newNode;

    return true;
}


void displaySinhVien(sv* head){
    struct SinhVien* current = head;

    while (current !=NULL){
        printf("Ma SV: %d\nHo ten SV: %s\nDiem mon hoc: %.2f\n", current->maSV, current->hoTen, current->diemMH);
        printf("\n");
        current = current->next;
    }
}


sv* findSinhVien(sv* head, int maSV){
    struct SinhVien* current = head;

    while(current != NULL){
        if (maSV == current->maSV){
            return current;
        }

        current = current->next;
    }

    return NULL;
}


void demSinhVienDuoiTrungBinh(sv* head){
    struct SinhVien* current = head;
    int count = 0;

    while(current != NULL){
        if (current->diemMH < 5){
            count++;
        }

        current = current->next;
    }

    printf("\nSo sinh vien co diem MH duoi trung binh: %d\n", count);
}


void tinhDiemTrungBinh(sv* head){
    sv* current = head;
    float sum = 0;
    float count = 0;
    float average;

    while(current != NULL){
        sum = sum + current->diemMH;
        count++;

        current = current->next;
    }

    average = sum/count;

    printf("\nDiem trung binh mon hoc cua ca lop la: %f\n", average);
}


void timSinhVienDiemCaoNhat(sv* head){
    struct SinhVien* current = head;
    struct SinhVien* SinhVien = NULL;
    float mark = 0;

    while(current != NULL){
        if(current->diemMH > mark){
            mark = current->diemMH;
            SinhVien = current;
        }

        current = current->next;
    }

    printf("\nSinh vien dau tien co diem mon hoc cao nhat:\n");
    printf("Ma SV: %d\nHo va ten: %s\nDiem mon hoc: %f\n", SinhVien->maSV, SinhVien->hoTen, SinhVien->diemMH);

}


void timMaSVCoDiemTrenTam(sv* head){
    struct SinhVien* current = head;

    printf("\nCac ma sinh vien co diem mon hoc tren 8:\n");
    while(current != NULL){
        if(current->diemMH > 8){
            printf("Ma sinh vien:%d\n", current->maSV);
        }

        current = current->next;
    }
}


void capNhatDiemMonHoc(sv* head){
    struct SinhVien* current = head;
    float diem;
    int maSV;

    printf("Nhap maSV:\n");
    scanf("%d", &maSV);

    printf("Nhap so diem muon cap nhat:\n");
    scanf("%f", &diem);

    while(current != NULL){
        if(maSV == current->maSV){
            printf("Cap nhat diem mon hoc cho sinh vien: %d\n", current->maSV);
            current->diemMH = diem;
        }

        current = current->next;
    }
}


int main(){
    sv SinhVienA = {123, "Nguyen A", 8.8};
    sv SinhVienB = {124, "Nguyen B", 9.7};
    sv SinhVienC = {125, "Nguyen C", 2.9};
    sv SinhVienD = {126, "Nguyen D", 9.7};
    sv SinhVienE = {127, "Nguyen E", 4.8};
    sv SinhVienF = {128, "Nguyen F", 7.5};

    sv* head = NULL;
    sv SinhVienArray[6];

    SinhVienArray[0] = SinhVienA;
    SinhVienArray[1] = SinhVienB;
    SinhVienArray[2] = SinhVienC;
    SinhVienArray[3] = SinhVienD;
    SinhVienArray[4] = SinhVienE;
    SinhVienArray[5] = SinhVienF;

    for(int i=0; i<6; i++){
        insertSinhVien(&head, SinhVienArray[i]);
    }

    displaySinhVien(head);

    int maSV;
    printf("Nhap ma sinh vien can tim:");
    scanf("%d", &maSV);

    struct SinhVien* foundSinhVien = findSinhVien(head, maSV);
    if (foundSinhVien != NULL){
        printf("Student found at memory address: %p\n", foundSinhVien);
    }

    demSinhVienDuoiTrungBinh(head);

    tinhDiemTrungBinh(head);

    timSinhVienDiemCaoNhat(head);

    timMaSVCoDiemTrenTam(head);

    capNhatDiemMonHoc(head);

    displaySinhVien(head);

    return 0;
}