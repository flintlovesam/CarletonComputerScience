#include <linux/init.h>

#include <linux/module.h>

#include <linux/kernel.h>

#include <linux/device.h>

#include <linux/fs.h>

#include <linux/uaccess.h> 



#define  DEVICE_TITLE "sam_prime"

#define  CLASS_NAME  "CharDevice"


static char message[256] = {0};


static int prime_return;

static int number_reads = 0;


static int major_number;

static short size_of_message;

static int err;

static struct device* sam_prime_device = NULL; //device struct *
static struct class*  sam_prime_class  = NULL; //class struct *





static int dev_open(struct inode *, struct file *);

static int dev_release(struct inode *, struct file *);

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset);

int compute_prime(int n);



static struct file_operations sam_prime_fops =
{

    .open = dev_open,

    .read = dev_read,

    .release = dev_release,

};



static char *sam_prime_devnode(struct device *dev, umode_t *mode);

static char *sam_prime_devnode(struct device *dev, umode_t *mode) {

    if(mode) *mode = 0444;

    return NULL;

}



static int __init sam_prime_init(void){



    printk(KERN_INFO "Init sam_prime module.\n");



    // Registered a major # for our character device

    major_number = register_chrdev(0, DEVICE_TITLE, &sam_prime_fops);

    if (major_number < 0) {

        printk(KERN_ALERT "sam_prime FAILED to register a major number.\n");

        return major_number;

    }

    printk(KERN_INFO "sam_prime REGISTERED correctly with major number %d\n", major_number);



    // Register a device class

    sam_prime_class = class_create(THIS_MODULE, CLASS_NAME);

    if (IS_ERR(sam_prime_class)) {

        unregister_chrdev(major_number, DEVICE_TITLE);

        printk(KERN_ALERT "sam_prime not registered a device class.\n");

        return PTR_ERR(sam_prime_class);

    }

    sam_prime_class->devnode = sam_prime_devnode;

    printk(KERN_INFO "sam_prime device class registered correctly\n");



    // Register the device driver

    sam_prime_device = device_create(sam_prime_class, NULL, MKDEV(major_number, 0), NULL, DEVICE_TITLE);

    if (IS_ERR(sam_prime_device)) {
	unregister_chrdev(major_number, DEVICE_TITLE);

        class_destroy(sam_prime_class);

        printk(KERN_ALERT "sam_prime failed to create the device.\n");

        return PTR_ERR(sam_prime_device);

    }

    printk(KERN_INFO "sam_prime successfully created with major number %d.\n", major_number);

    return 0;

}



static int dev_open(struct inode *inodep, struct file *filep){

    printk(KERN_INFO "sam_prime device opened.\n");

    return 0;

}



static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset)

{

    number_reads++;

    err = 0;

    prime_return = compute_prime(number_reads);

    sprintf(message, "%d", prime_return);

    size_of_message = strlen(message);



    err = copy_to_user(buffer, message, size_of_message);

   
 if (err==0) { // condtion met if success

      printk(KERN_INFO "mydriver: sent %d characters to user\n", size_of_message);

      return (size_of_message=0); // reset size of the message to 0 and return 0

    }

    else {

      printk(KERN_INFO "mydriver: failed to send %d characters to the user\n", err);

      return -EFAULT; // fail

    }

}





// destroy the device, unregister the device class, remove the device class , unregister the major number
static void __exit sam_prime_exit(void){

   device_destroy(sam_prime_class, MKDEV(major_number, 0));     

   class_unregister(sam_prime_class);                         

   class_destroy(sam_prime_class);                             

   unregister_chrdev(major_number, DEVICE_TITLE);             

   printk(KERN_INFO "EBBChar: \n");

}

static int dev_release(struct inode *inodep, struct file *filep){

    printk(KERN_INFO "sam_prime device closed\n");

    number_reads = 0;

    return 0;

}


  // Return nth prime number

int compute_prime(int n) {

  int possiblePrime = 2;	
   int factor;

 

   while (true) {

      int prime = true;

      
// test for prime number occuring by modulus division

      for (factor = 2; factor < possiblePrime; ++factor)

         if (possiblePrime % factor == 0) {

            prime = false;

            break;

         }

      // check if prime number is found

      if (prime) {

         if (--n == 0) {


		    return possiblePrime;

         }

      }

      ++possiblePrime;

   }

}



module_init(sam_prime_init);

module_exit(sam_prime_exit);






