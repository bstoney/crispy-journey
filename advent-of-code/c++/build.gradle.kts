plugins {
    `cpp-application`
    `cpp-unit-test`
}

application {
    baseName = "advent-of-code"
    targetMachines.add(machines.linux.x86_64)
    source.setFrom("src")
    binaries.configureEach {
        compileTask.get().compilerArgs.add("-std=c++20")
    }
}

tasks {
    register<Exec>("runApp") {
        dependsOn("build")
        workingDir(rootProject.projectDir)
        commandLine(projectDir.path + "/build/exe/main/debug/" + application.baseName.get())
    }
}
