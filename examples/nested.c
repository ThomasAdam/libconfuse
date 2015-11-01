/* Example by Thomas Adam */

#include <confuse.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	cfg_opt_t group_opts[] = {
		CFG_INT("number", 0, CFGF_NONE),
		CFG_END()
	};
	cfg_opt_t groups_opts[] = {
		CFG_STR("name", "Esmé", CFGF_NONE),
		CFG_SEC("group", group_opts, CFGF_TITLE | CFGF_MULTI),
		CFG_END()
	};
	cfg_opt_t opts[] = {
		CFG_SEC("groups", groups_opts, CFGF_NONE),
		CFG_END()
	};
	cfg_t *cfg;

	cfg = cfg_init(opts, CFGF_NONE);
	if (cfg_parse(cfg, "nested.conf") == CFG_PARSE_ERROR)
		return 1;

	cfg_free(cfg);

	return 0;
}

/**
 * Local Variables:
 *  version-control: t
 *  indent-tabs-mode: t
 *  c-file-style: "linux"
 * End:
 */
