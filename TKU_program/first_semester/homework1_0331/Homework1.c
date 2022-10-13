#include <stdlib.h>
#include <stdio.h>
#define student_num  30
#define question_num  20

char right_ans[question_num+1],student_ans[student_num+1][question_num+1];
int student_ID[student_num];
int student_wrong[student_num] = {0};
int wrongcount[question_num] = {0};
int total;

void fgetAnswers(void);
int main()
{
    fgetAnswers();
//=====================計算錯幾題以及學生錯誤題數===========================
    for(int i=0;i<student_num;i++){
        for(int j=0;j<question_num;j++){
            if(student_ans[i][j]!=right_ans[j]){
                student_wrong[i]++;
                wrongcount[j]++;
            }
        }
    }
//==========================================================================
//=======================計算成績===========================================
    float student_score[student_num];
    for(int i=0;i<student_num;i++){
        student_score[i] = ((20.0-student_wrong[i])/20)*100;
    }
//==========================================================================
//=====================創建與存入report.TXT=================================
    FILE *fp;
    fp = fopen("report.txt","w+");

    fprintf(fp,"\t\t Exam Report\n");
    fprintf(fp,"Question\t");
    for(int i=0;i<question_num;i++) fprintf(fp,"%2d ",i+1);
    fprintf(fp,"\nAnswer\t\t");
    for(int i=0;i<question_num;i++) fprintf(fp,"%2c ",right_ans[i]);
    fprintf(fp,"\n\n\nID\tScore(%%)\n");
    for(int i=0;i<student_num;i++) fprintf(fp,"%d\t%.0f\n",student_ID[i],student_score[i]);
    fprintf(fp,"\n\nQuestion\t");
    for(int i=0;i<question_num;i++) fprintf(fp,"%2d ",i+1);
    fprintf(fp,"\nAnswer\t\t");
    for(int i=0;i<question_num;i++) fprintf(fp,"%2d ",wrongcount[i]);

    fclose(fp);
//==========================================================================
    return 0;
}
//=======================讀examdat.TXT======================================
void fgetAnswers(void)
{
    FILE *inp;
    inp = fopen("examdat.txt","r");

    fscanf(inp,"%d",&total);
    fscanf(inp,"%s",right_ans);

    int i=0;
    while(fscanf(inp,"%d",&student_ID[i])!=EOF){
        fscanf(inp,"%s",&student_ans[i]);
        i++;
    }
    fclose(inp);
}
//===========================================================================