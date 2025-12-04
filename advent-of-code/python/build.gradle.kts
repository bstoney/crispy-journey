plugins {
    idea
}

idea {
    module {
        // TODO find out how to make this work
        // jdkName = "Python 3.12.3"
    }
}

tasks {
    register<Exec>("runPythonScript") {
        workingDir(rootProject.projectDir)
        environment("PYTHONPATH", projectDir.path)
        commandLine("python", projectDir.path + "/src/adventofcode/app.py")
    }
}