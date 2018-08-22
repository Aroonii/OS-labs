#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/jiffies.h>
#include <linux/utsname.h>

//Custom Functions
void uptime(void);
void getSystemInfo(void);
void addStudents(int ID, int age, char* name);
void list(void);

typedef struct student {
int ID;
int age;
char* name;
};

int a = 0;
struct student studArray[3];


void addStudents(int ID, int age, char* name) {
	studArray[a].ID =ID;
	studArray[a].age =age;
	studArray[a].name = name;
	a = a+1;
}

void list(void){
	int i;
	printk("Student Array: => \n");
	for(i =0; i<a; i++){
		printk("Name: %s\n", studArray[i].name);
		printk("ID: %i\n", studArray[i].ID);
		printk("Age: %i\n\n", studArray[i].age);
	}
}
/* This function is called when the module is loaded. */
int simple_init(void)
{
       printk(KERN_INFO "Loading Arooniis Module\n");
	uptime();
	getSystemInfo();
	addStudents(142,23,"Arun");
	addStudents(153,30,"Peter");
	addStudents(203,15,"Alex");
	list();
       return 0;
}
	

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Arooniis Module\n");
}

//Gets the uptime
void uptime() {
	printk("Uptime: %i\n", jiffies_to_msecs(get_jiffies_64())/1000);
}

void getSystemInfo(){
	struct new_utsname *buf;
	buf = utsname();
	
	printk("Nodename: %s\n", buf->nodename);
	printk("Machine: %s\n", buf->machine);
	printk("Sysname: %s\n", buf->sysname);
	printk("Release: %s\n", buf->release);
	printk("Versios: %s\n", buf->version);
#ifdef __linux__
	printk("Doomain name: %s\n", buf->domainname); //GNU extension
#endif
}


/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

