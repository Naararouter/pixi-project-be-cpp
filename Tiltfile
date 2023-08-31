load('ext://restart_process', 'docker_build_with_restart')

# Specify the Kubernetes resources
k8s_yaml(helm('./helm-wc2r', values=['./helm-wc2r/values.dev-local.yaml']))


gamesession_api_path = './packages/gamesession-api'

# Specify how to build and deploy the gamesession-api with live update
docker_build_with_restart('gamesession-api', gamesession_api_path,
    entrypoint='/usr/src/app/build/test-exe',
    dockerfile=gamesession_api_path + '/Dockerfile',
    live_update=[
        sync(gamesession_api_path, '/usr/src/app'),
        run('cd /usr/src/app && mkdir -p build && cd build && cmake .. && make'),
    ]
)
k8s_resource('gamesession-api-deployment', port_forwards=8000)

# The db-postgres image is pre-built and pulled from Docker Hub, so there's no need to build it ourselves
k8s_resource('db-postgres-deployment', port_forwards=5432)
