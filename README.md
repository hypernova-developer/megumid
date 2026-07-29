# megumid (Megumi Daemon)

`megumid` is a lightweight, low-overhead Linux system daemon written in modern C++20. Operating entirely in the background as a systemd service, it orchestrates autonomous infrastructure mitigation by continuously supervising the compliance pipelines of the `mahoraga` scanning engine.

## Architecture & Design Principles

The project strictly follows a decoupled, modular software design pattern to eliminate monolithic single points of failure:

* **Process Pipeline Supervision:** Leverages non-blocking process pipelines (`popen`) to capture headless execution streams from the runtime engine without introduces CPU-bound polling overhead.
* **Deterministic Event Parsing:** Implements memory-efficient string transformation and pattern tokenization to detect system anomalies (`abnormal` signatures) in real-time.
* **Decoupled Mitigation Execution:** Isolates the threat detection domain from the defensive action layer via a dedicated orchestration module, enabling highly extensible runtime countermeasures.
- **Resource Lifecycle Management:** Hooks directly into native Linux signal layers (`SIGINT`, `SIGTERM`) to guarantee strict resource cleanup, automatic pipe closure, and deterministic shutdown states, preventing zombie processes.

## Project Structure

```text
megumid/
├── bin/          # Compiled production-grade binaries
├── config/       # Local service configuration profiles
├── scripts/      # Automation scripts for local environments
└── src/          # C++20 source and header codebase

```

## Compilation and Deployment

### Prerequisites

Ensure your system incorporates the standard GNU Compiler Collection supporting C++20 features:

```bash
sudo apt update && sudo apt install build-essential git

```

### Local Build Workflow

To build the executable binary deterministically under the production flag configurations, execute the provided build automation script:

```bash
cd scripts
chmod +x build.sh
./build.sh

```

The resulting binary will be extracted to the `bin/` directory as `megumid`.

## Systemd Integration

To establish `megumid` as an active background daemon under systemd control, deploy the following unit configuration to `/etc/systemd/system/megumid.service`:

```ini
[Unit]
Description=Megumi Daemon - Autonomous cgroup Defense Service
After=network.target

[Service]
Type=simple
ExecStart=/usr/local/bin/megumid
Restart=always
RestartSec=5
StandardOutput=journal
StandardError=journal

[Install]
WantedBy=multi-user.target

```

Reload the systemd manager configuration and enable the service persistence state:

```bash
sudo systemctl daemon-reload
sudo systemctl enable megumid.service
sudo systemctl start megumid.service

```

## License

This project is open-source software licensed under the terms of GPLv3 specified within the `LICENSE` repository file.
