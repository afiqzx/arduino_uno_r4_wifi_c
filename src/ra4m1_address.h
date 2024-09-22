


// Control register base address
#define P0CR_BASE (0x40040000)              // PORT0 
#define P1CR_BASE (P0CR_BASE + 0x00000020)  // PORT1 
#define P2CR_BASE (P0CR_BASE + 0x00000040)  // PORT2 
#define P3CR_BASE (P0CR_BASE + 0x00000060)  // PORT3 
#define P4CR_BASE (P0CR_BASE + 0x00000080)  // PORT4 
#define P5CR_BASE (P0CR_BASE + 0x000000A0)  // PORT5 
#define P6CR_BASE (P0CR_BASE + 0x000000C0)  // PORT6 
#define P7CR_BASE (P0CR_BASE + 0x000000E0)  // PORT7 
#define P8CR_BASE (P0CR_BASE + 0x00000100)  // PORT8 
#define P9CR_BASE (P0CR_BASE + 0x00000120)  // PORT9 


// Port 0,5-9 offset
#define PCR1 

#define PFS (P0CR_BASE + 0x800)
