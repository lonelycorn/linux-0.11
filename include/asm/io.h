/// Write a byte (@p value) to @p port. Go as fast as it can.
#define outb(value,port) \
__asm__ ("outb %%al,%%dx"::"a" (value),"d" (port))

/// Read a byte from @p port. Go as fast as it could
#define inb(port) ({ \
unsigned char _v; \
__asm__ volatile ("inb %%dx,%%al":"=a" (_v):"d" (port)); \
_v; \
})

/// Write a byte (@p value) to @p port. May pause before returning
/// FIXME: what does 'pause' mean?
#define outb_p(value,port) \
__asm__ ("outb %%al,%%dx\n" \
		"\tjmp 1f\n" \
		"1:\tjmp 1f\n" \
		"1:"::"a" (value),"d" (port))

/// Read a byte from @p port. May pause before returning
#define inb_p(port) ({ \
unsigned char _v; \
__asm__ volatile ("inb %%dx,%%al\n" \
	"\tjmp 1f\n" \
	"1:\tjmp 1f\n" \
	"1:":"=a" (_v):"d" (port)); \
_v; \
})
