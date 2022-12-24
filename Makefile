bnobackend:
	cmake . -B nobackend/build
	make -C nobackend/build

bvulkan:
	cmake . -DBACKEND_VULKAN=ON -B vulkan/build
	make -C vulkan/build

bmetal:
	cmake . -DBACKEND_METAL=ON -B metal/build
	make -C metal/build

bopengl:
	cmake . -DBACKEND_OPENGL=ON -B opengl/build
	make -C opengl/build
