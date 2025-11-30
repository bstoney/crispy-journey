plugins {
    `cpp-application`
    `cpp-unit-test`
}

application {
    targetMachines.add(machines.linux.x86_64)
    source.setFrom("src")
    binaries.configureEach {
        compileTask.get().compilerArgs.add("-std=c++20")
    }
}
