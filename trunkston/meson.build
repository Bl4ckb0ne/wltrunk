trunkston_src = [
	'main.c',
]

trunkston_deps = [
	wlroots,
	wlr_protos,
]

trunkston = executable(
	'trunkston',
	trunkston_src,
	dependencies: trunkston_deps,
	link_with : wltrunk_lib,
	build_by_default: get_option('trunkston'),
)

