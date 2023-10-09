#include <shadow.h>
#include <stdio.h>

int main(){
    struct spwd *spw;

    spw = getspnam("joonho");
    printf("Login Name : %s\n", spw->sp_namp);
    printf("Passwd : %s\n", spw->sp_pwdp);
    printf("last change : %ld\n", spw->sp_lstchg);
}