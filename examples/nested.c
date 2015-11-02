/* Example by Thomas Adam */

#include <confuse.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	cfg_opt_t group_opts[] = {
		CFG_INT("number", 0, CFGF_NONE),
		CFG_INT("total", 0, CFGF_NONE),
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

	int	 no_of_groups, no_of_group;
	int	 i, j;
	cfg_t	*groups_cfg, *group_cfg;

	/* Iterate over the sections and print fields from each section. */
	no_of_groups = cfg_size(cfg, "groups");
	for (i = 0; i < no_of_groups; i++) {
		groups_cfg = cfg_getnsec(cfg, "groups", i);

		no_of_group = cfg_size(groups_cfg, "group");
		for (j = 0; j < no_of_group; j++) {
			group_cfg = cfg_getnsec(groups_cfg, "group", j);

			printf("group title: '%s'\n", cfg_title(group_cfg));
			printf("group total: %d\n", cfg_getint(group_cfg,
				"total"));
			printf("\n");
		}
	}

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
