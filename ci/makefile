build:
	@docker-compose -f docker-compose.yml -p example build developer

run:
	@docker-compose -f docker-compose.yml -p example up -d developer
	@docker attach example_developer_1

stop:
	@docker-compose -f docker-compose.yml -p example stop

remove-dangling-images:
	@docker rmi `docker images -q -f dangling=true`

remove-all-images:
	@docker rmi --force `docker images -q -a`
