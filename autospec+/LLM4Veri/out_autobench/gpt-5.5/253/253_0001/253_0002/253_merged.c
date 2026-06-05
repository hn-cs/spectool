// from x509-parser
// https://github.com/ANSSI-FR/x509-parser/blob/6f3bae3c52989180df6af46da1acb0329315b82a/src/x509-common.c#L2235-L2273

#include <stdint.h>
#include <unistd.h>
#include <string.h>

typedef uint8_t	  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

#define X509_FILE_NUM 1

#define X509_FILE_LINE_NUM_ERR ((X509_FILE_NUM * 100000))


/*@
requires len == 0 || \valid_read(buf + (0..len-1));
ensures (buf == \null || len == 0) ==> \result == -X509_FILE_LINE_NUM_ERR;
ensures (buf != \null && len > 0 && (\forall integer i; 0 <= i < len ==> buf[i] <= 0x7f)) ==> \result == 0;
ensures (buf != \null && len > 0 && (\exists integer i; 0 <= i < len && buf[i] > 0x7f)) ==> \result == -X509_FILE_LINE_NUM_ERR;
assigns \nothing;
*/
static int check_ia5_string(const u8 *buf, u32 len)
{
	int ret;
	u32 i;

	if ((buf == NULL) || (len == 0)) {
		ret = -X509_FILE_LINE_NUM_ERR;
		//ERROR_TRACE_APPEND(X509_FILE_LINE_NUM_ERR);
		goto out;
	}

	/*@
	loop invariant i <= len;
	loop invariant \forall integer k; 0 <= k < i ==> buf[k] <= 0x7f;
	loop invariant 0 <= i;
	loop assigns ret;
	loop assigns i;
	*/
	for (i = 0; i < len; i++) {
		if (buf[i] > 0x7f) {
			ret = -X509_FILE_LINE_NUM_ERR;
			//ERROR_TRACE_APPEND(X509_FILE_LINE_NUM_ERR);
			goto out;
		}
	}

	ret = 0;

out:
	return ret;
}


int main() {
	u8 buf[5];
	u32 len = 5;

	int ret = check_ia5_string(buf, len);
	//@ assert ret == -X509_FILE_LINE_NUM_ERR ==> \exists integer i; 0 <= i < len && buf[i] > 0x7f;
	//@ assert ret == 0 ==> \forall integer i; 0 <= i < len ==> (buf[i] <= 0x7f);

	return ret;
}