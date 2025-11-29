plugins {
    kotlin("jvm") version "2.3.0-RC"
}

sourceSets {
    main {
        kotlin.srcDir("src")
    }
    test {
        kotlin.srcDir("tst")
    }
}

dependencies {
    testRuntimeOnly("org.junit.platform:junit-platform-launcher")
    testImplementation("org.assertj:assertj-core:3.27.6")
    testImplementation("org.junit.jupiter:junit-jupiter:6.0.1")
}

tasks {
    withType<Test> {
        configureEach {
            workingDir(rootProject.projectDir)
            useJUnitPlatform()
        }
    }
}

kotlin {
    jvmToolchain(25)
}