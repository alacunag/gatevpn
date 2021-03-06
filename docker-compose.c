version: "2.1"
services:
  WG_PaaS:
    build: .
    container_name: WG_PaaS
    cap_add:
      - NET_ADMIN
      - SYS_MODULE
    environment:
      - PUID=1000
      - PGID=1000
      - TZ=Asia/Kolkata
      - SERVERURL=<appname>.herokuapp.com #optional
      - SERVERPORT=2370 #optional
      - PEERS=1 #optional
      - PEERDNS=1.1.1.1 #optional
      - INTERNAL_SUBNET=3.7.9.0 #optional
    volumes:
      - config/:/config
      - /lib/modules:/lib/modules
    ports:
      - 2370:2370/udp
    sysctls:
      - net.ipv4.conf.all.src_valid_mark=1
    restart: unless-stopped
