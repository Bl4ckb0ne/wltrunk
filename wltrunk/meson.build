wltrunk_src = files(
  'backend.c',
)

wltrunk_deps = [
	wlroots,
	wayland_server,
	pixman,
	xkbcommon,
	wlr_protos
]

wltrunk_lib = library(
	'wltrunk',
	wltrunk_src,
	include_directories: includes,
	dependencies: wltrunk_deps,
	install: true
)

pkgconfig = import('pkgconfig')
pkgconfig.generate(
	libraries: wltrunk_lib,
	version: meson.project_version(),
	filebase: meson.project_name(),
	name: meson.project_name(),
	description: 'Wayland compositor library',
)
