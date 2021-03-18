#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

//created the structure where the students information
struct Student{
    char name[20], address[30], contact[15], age[4];
}s[100]; //variable s denotes the structure and array is added of 100 size

void TextFile();
void OverwriteData();
void DataInTerminal();
void Createfile();
void AddData();
void Readdata();
void SeparateData();
void OneTab(char *mline, char *line);
void AddInput();
void ArrangeData();
int CheckFile();

int stu, dat = -1;
char namet[20], sname1[20], sname2[20], addresst[30], contactt[15], aget[4], line[250];
char filename[15];

void main() {

    char txtcr[4], file[4], newFile[4], refile[4];

    /*
        This is where the program starts and ask questions.
        And the task is done according to answer given by the user of the questions.
        It all process here.
    */

    printf("The text file you want exists or not? [Y/N]: ");
    scanf("%s",txtcr);

    for(int i = 0; txtcr[i] != '\0'; i++) {
        if(txtcr[i] >= 'A' && txtcr[i] <= 'Z'){
            txtcr[i] += 32;
        }
    }

    EnterFileName:
    if(strcmp(txtcr, "yes") == 0 || strcmp(txtcr, "y") == 0) {
        printf("\nEnter the name of the file: ");
        scanf("%s",filename);
        int cf = CheckFile();
        if(cf == -1) {
            printf("\nDo you want to create the new file? [Y/N]: ");
            scanf("%s",newFile);

            for(int i = 0; newFile[i] != '\0'; i++) {
                if(newFile[i] >= 'A' && newFile[i] <= 'Z'){
                    newFile[i] += 32;
                }
            }

            if(strcmp(newFile, "yes") == 0 || strcmp(newFile, "y") == 0) {
                printf("\nEnter the name of the file to create: ");
                scanf("%s",filename);
                Createfile();
                printf("\n");
                OverwriteData();
            }
            else if(strcmp(newFile,"no") == 0 || strcmp(newFile,"n") == 0) {
                printf("\nPress any key to continue.......");
                getch();
                system("cls");
                printf("Do you want to enter the filename again? [Y/N]: ");
                scanf("%s",refile);
                for(int i = 0; refile[i] != '\0'; i++) {
                    if(refile[i] >= 'A' && refile[i] <= 'Z'){
                        refile[i] += 32;
                    }
                }
                if(strcmp(refile,"yes") == 0 || strcmp(refile,"y") == 0){
                    goto EnterFileName;
                }
                if(strcmp(refile,"no") == 0 || strcmp(refile,"n") == 0){
                    printf("\nPress any key to exit........");
                    getch();
                    return;
                }
            }
        }
        else if(cf == 0) {
            printf("\nDo you want to overwrite the text file or add some students data? [Y/N]: ");
            scanf("%s",file);
            printf("\n");

            for(int i = 0; file[i] != '\0'; i++) {
                if(file[i] >= 'A' && file[i] <= 'Z'){
                    file[i] += 32;
                }
            }

            if(strcmp(file, "yes") == 0 || strcmp(file, "y") == 0) {
                OverwriteData();
            }
            else if(strcmp(file,"no") == 0 || strcmp(file,"n") == 0) {
                AddData();
            }
        }

    }
    else if(strcmp(txtcr,"no") == 0 || strcmp(txtcr,"n") == 0) {
        printf("\nEnter the name of the file to create: ");
        scanf("%s",filename);
        Createfile();
        printf("\n");
        OverwriteData();
    }

    printf("\nPress any key to exit.......");
    getch();

}

/*
    In this function TextFile(),
    All the data of the students are printed in txt file,
    wheather the txt is overwritten or added the data or created new file. 
*/

void TextFile() {
    FILE *students;

    students = fopen(filename, "w");

    fprintf(students, "\nS.N\t\tName\t\t\t\tAge\t\tContact\t\t\tAddress\n");
    for(int i = 0, c, j = 1; i < stu; i++, j++) {
        for(c = 0; s[i].name[c] != '\0'; c++){}
        if(c > 15){
            fprintf(students, "\n%d\t\t%s\t%s\t\t%s\t\t%s",j,s[i].name,s[i].age,s[i].contact,s[i].address);
        }
        else {
            fprintf(students, "\n%d\t\t%s\t\t%s\t\t%s\t\t%s",j,s[i].name,s[i].age,s[i].contact,s[i].address);
        }
    }

    fclose(students);

}

/*
    In this function OverwriteData(),
    The input of student is taken if the txt is going to overwritten or written in a new file.
*/

void OverwriteData() {

    printf("Press any key to continue.........");
    getch();
    system("cls");

    printf("Enter the total number of students: ");
    scanf("%d",&stu);
    printf("\n");

    for(int i = 0; i < stu; i++) {
        printf("Name: ");
        scanf(" %[^\n]",s[i].name);
        printf("Age: ");
        scanf("%s",&s[i].age);
        printf("Contact number: ");
        scanf("%s",s[i].contact);
        printf("Address: ");
        scanf(" %[^\n]",s[i].address);
        printf("\n");
    }

    ArrangeData();

    TextFile();

    char out[4];

    printf("Do you want to show the output in the terminal? [Y/N]: ");
    scanf("%s",out);

    for(int i = 0; out[i] != '\0'; i++){
        if(out[i] >= 'A' && out[i] <= 'Z') {
            out[i] += 32;
        }
    }

    if(strcmp(out,"yes") == 0 || strcmp(out, "y") == 0){
        DataInTerminal();
    }
    else if(strcmp(out,"no") == 0 || strcmp(out,"n") == 0) {
        return;
    }

}

/*
    If you want to see the output in terminal,
    then the following codes on function DataInTerminal(),
    will print it.
*/

void DataInTerminal() {
    printf("Press any key to continue...........");
    getch();
    system("cls");

    //this will print the students data in terminal according to aplphabetical order as it is processed above
    printf("\nS.N\t\tName\t\t\t\tAge\t\tContact no.\t\tAddress\n");
    for(int i = 0, c, j = 1; i < stu; i++, j++) {
        for(c = 0; s[i].name[c] != '\0'; c++){}
        if(c > 15){
            printf("\n%d\t\t%s\t%s\t\t%s\t\t%s",j,s[i].name,s[i].age,s[i].contact,s[i].address); //if someone's name is longer, then it will decrease a space so that the table will be in proper format
        }
        else {
            printf("\n%d\t\t%s\t\t%s\t\t%s\t\t%s",j,s[i].name,s[i].age,s[i].contact,s[i].address); //for someone's whose name won't be longer and don't disturb the spacing problem in the table(output)
        }
    }
}

/*
    The function CheckFile(),
    will check the filename entered
    is correct or not.
    If not then the error is value is returned to
    let user again enter the filename or create the file.
    Note that: .txt is not compulsory while giving input.
    It will automatically add .txt at last so that it will not be boring while
    typing filename.
*/

int CheckFile() {

    int filelen;
    char check[5];
    strcpy(check,"\0");
    for(filelen = 0; filename[filelen] != 0; filelen++) {}

    for(int i = filelen - 4, j = 0; i < filelen; i++, j++){
        check[j] = filename[i];
    }

    if(strcmp(check,".txt") != 0) {
        strcpy(check,".txt");
        for(int i = filelen, j = 0; i < filelen + 5; i++, j++) {
            filename[i] = check[j];
        }
    }

    filelen = 0;

    FILE *checkFile;

    checkFile = fopen(filename, "r");

    if(checkFile == NULL) {
        printf("\nFile not found!\n");
        return -1;
    }
    else {
        printf("\nFile found!! \n");
    }

    fclose(checkFile);

    return 0;

}

/*
    The function Createfile(),
    will create the file with the 
    filename given by user.
    Note that: .txt is not compulsory while giving input.
    It will automatically add .txt at last so that it will not be boring while
    typing filename.
*/

void Createfile() {

    int filelen;
    char check[5];
    for(filelen = 0; filename[filelen] != 0; filelen++) {}

    for(int i = filelen - 4, j = 0; i < filelen; i++, j++){
        check[j] = filename[i];
    }

    if(strcmp(check,".txt") != 0) {
        strcpy(check,".txt");
        for(int i = filelen, j = 0; i < filelen + 5; i++, j++) {
            filename[i] = check[j];
        }
    }

}

/*
    If the user had to add the data,
    then the function AddData() will do the processes
*/

void AddData() {

    Readdata();
    AddInput();
    TextFile();

    char out[4];

    printf("Do you want to show the output in the terminal? [Y/N]: ");
    scanf("%s",out);

    for(int i = 0; out[i] != '\0'; i++){
        if(out[i] >= 'A' && out[i] <= 'Z') {
            out[i] += 32;
        }
    }

    if(strcmp(out,"yes") == 0 || strcmp(out, "y") == 0){
        DataInTerminal();
    }
    else if(strcmp(out,"no") == 0 || strcmp(out,"n") == 0) {
        return;
    }
    
}

/*
    The function Readdata(),
    will help to read the data already existed on txt file.
*/

void Readdata() {

    FILE *readData;

    readData = fopen(filename, "r");

    int skip = 0;

    while(fgets(line,250,readData)) {
        if(skip<=2) {
            skip++;
            continue;
        }
        dat++;
        SeparateData();
    }

    fclose(readData);

}

/*
    The function SeparateData(),
    will help to separate the data in existed file into,
    name, age, contact and address.
*/

void SeparateData() {

    char sepDat[50][50] = {"\0"};
    int c = 0;

    /*
        This loop will help to remove
        line spacing '\n' from the data.
    */
    for(int i = 0, j = 0; line[i] != '\0'; i++) {
        if(line[i] == '\n' && line[i+1] != '\0') {
            for(int j = i; line[j] != '\0'; j++) {
                line[j] = line[j+1];
            }
            line[j] = '\0';
        }
        else if(line[i] == '\n' && line[i+1] == '\0') {
            line[i] = '\0';
        }
    }

    char mline[strlen(line)+1];

    OneTab(mline, line);

    /*
        This loop separates the data into
        name, age, contact and address 
        with every tab space '\t'.
    */
    for(int i = 0, j = 0; mline[i] != '\0'; i++) {

        if(mline[i] == '\t' || mline[i] == '\0') {
            sepDat[c][j] = '\0';
            j = 0;
            c++;
        }
        else {
            sepDat[c][j] = mline[i];
            j++;
        }
    }

    strcpy(s[dat].name, sepDat[1]);
    strcpy(s[dat].age, sepDat[2]);
    strcpy(s[dat].contact, sepDat[3]);
    strcpy(s[dat].address, sepDat[4]);   

}

/*
    The function OneTab(),
    converts all contionuous many tab spaces '\t'
    into single tab space '\t'
*/
void OneTab(char *mline, char *line) {

    int i,j;

    for(i = 0, j = 0; line[i] != '\0'; i++,j++) {
        if(line[i] == '\t' && line[i+1] == '\t') {
            j--;
            continue;
        }
        mline[j] = line[i];
    }

    mline[j] = '\0';

}

/*
    The function AddInput(),
    ask the user to enter the data of the students
    to add in the existing file containing data
    by not clearing any of the data existed
*/

void AddInput() {

    printf("Enter the number of students to add: ");
    scanf("%d",&stu);
    printf("\n");

    dat++;
    stu += dat;

    for(int i = dat; i < stu; i++) {
        printf("Name: ");
        scanf(" %[^\n]",s[i].name);
        printf("Age: ");
        scanf("%s",&s[i].age);
        printf("Contact number: ");
        scanf("%s",s[i].contact);
        printf("Address: ");
        scanf(" %[^\n]",s[i].address);
        printf("\n");
    }

    ArrangeData();

}

/*
    The function ArrangeData(),
    will arrange the every students data
    in alphabetical order.
*/

void ArrangeData() {

    /*
        In this loop the students data are arranged in alphabetical order
    */
    for(int i = 0; i < stu; i++) {
        for(int j = i + 1; j < stu; j++) {
            for(int c = 0; s[i].name[c] != '\0'; c++) {
                if(s[i].name[c] >='A' && s[i].name[c] <='Z') {
                    sname1[c] = s[i].name[c] + 32;      //for converting all the capital letters to small so that the comparing the alphabets for sorting will be easy
                }
                else if(s[i].name[c] >='a' && s[i].name[c] <='z'){
                    sname1[c] = s[i].name[c];           //for storing the small letter same as it is. Now the name is stored in another variable in all small letters for comparison
                }
            }

            //this loop do task same as above but for another name which will be compared from the name which is processed above
            for(int c = 0; s[j].name[c] != '\0'; c++) {
                if(s[i].name[c] >='A' && s[j].name[c] <='Z') {
                    sname2[c] = s[j].name[c] + 32;
                }
                else if(s[j].name[c] >='a' && s[j].name[c] <='z'){
                    sname2[c] = s[j].name[c];
                }
            }

            //this is where the names are compared and sorted in alphabetical order
            if(strcmp(sname1 , sname2) > 0) {
                strcpy(namet, s[i].name);
                strcpy(s[i].name, s[j].name);
                strcpy(s[j].name, namet);

                strcpy(aget, s[i].age);
                strcpy(s[i].age, s[j].age);
                strcpy(s[j].age, aget);

                strcpy(contactt, s[i].contact);
                strcpy(s[i].contact, s[j].contact);
                strcpy(s[j].contact, contactt);

                strcpy(addresst, s[i].address);
                strcpy(s[i].address, s[j].address);
                strcpy(s[j].address, addresst);
            }
        }
    }

    //this loop will make the first letter of the word of the address capital
    for(int i = 0; i < stu; i++) {
        for(int c = 0; s[i].address[c] != '\0'; c++){
            if(s[i].address[c] >='a' && s[i].address[c] <='z') {
                if(c == 0) {
                    s[i].address[c] -= 32;
                }
            }
            if(s[i].address[c] == ' ') {
                c++;
                if(s[i].address[c] >='a' && s[i].address[c] <='z') {
                    s[i].address[c] -= 32;
                }
            }
        }
    }

    //In this loop the first letter of first, middle and last name are made capital
    for(int i = 0; i < stu; i++) {
        for(int c = 0; s[i].name[c] != '\0'; c++){
            if(s[i].name[c] >='a' && s[i].name[c] <='z') {
                if(c == 0) {
                    s[i].name[c] -= 32;             //if the name which is given by user starts from small letter. Then it will make the first letter of the first name capital
                }
            }
            if(s[i].name[c] == ' ') {
                c++;
                if(s[i].name[c] >='a' && s[i].name[c] <='z') {
                    s[i].name[c] -= 32;             //for converting the first letter of the middle name or last name to capital if they are in small
                }
            }
        }
    }

}
