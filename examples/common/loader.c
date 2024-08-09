#include <xdp/libxdp.h>
#define IFINDEX 1


int main(int argc, char **argv) {
    struct xdp_program *prog = xdp_program__open_file(argv[1], argv[2], NULL);
    const char *prog_name = xdp_program__name(prog);
    if (strcmp(prog_name, argv[3])) {
        printf("Expected function %s, got %s", argv[3], prog_name);
        return 1;
    }
    printf("Opened program: %s %s\n", argv[1], argv[3]);
    
    int err = xdp_program__attach(prog, IFINDEX, XDP_MODE_SKB, 0);

    printf("HERHEERE");

    if (!err)
        xdp_program__detach(prog, IFINDEX, XDP_MODE_SKB, 0);

    printf("CLOSING");
    xdp_program__close(prog);
    
    
    
    /*
    struct bpf_object* obj = bpf_object__open(argv[1]);
    if (bpf_object__load(obj)) {
		printf("Failed to load program\n");
		return 1;
	}
    struct bpf_program* prog = bpf_object__find_program_by_name(obj, argv[2]);
    bpf_program__set_type(prog, BPF_PROG_TYPE_XDP);
    int progFd = bpf_program__fd(prog);
    const char *prog_name = bpf_program__name(prog);
    printf("Loaded XDP program %s", prog_name);

    int ifindex = if_nametoindex(argv[3]);
	if (!ifindex) {
        printf("Could not find interface %s", argv[3]);
		return 1;
	}

	int err = bpf_program__attach_xdp(ifindex, progFd);
	if (err) {
		printf("Error while loading bpf program\n");
		return 1;
	}

	return 0;
*/
}