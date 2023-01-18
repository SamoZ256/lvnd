bnobackend:
	cmake -G "MinGW Makefiles" . -B build/nobackend
	make -C build/nobackend

bvulkan:
	cmake . -DBACKEND_VULKAN=ON -B build/vulkan
	make -C build/vulkan

bmetal:
	cmake . -DBACKEND_METAL=ON -B build/metal
	make -C build/metal

bopengl:
	cmake . -DBACKEND_OPENGL=ON -B build/opengl
	make -C build/opengl
