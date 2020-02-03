{
	"targets": [{
		"target_name": "rpserver",
		"cflags!": [],
		"cflags_cc!": [], 
		"sources": [
			"src/main.cpp"
		],
		'include_dirs': [
			"<!(node -p \"require('node-addon-api').include\")"
		],
		'libraries': [], 
		'dependences': [
			"<!(node -p \"require('node-addon-api').gyp\")"
		],
		'defines': ['NAPI_DISABLE_CPP_EXTENSIONS']
	}]
}
