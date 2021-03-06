i# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## [Unreleased]
### Added
- Guard to Sentry init

## [0.12.2] - 2021-02-15
### Added
- Exceptions tracking with Sentry

## [0.12.1] - 2021-01-22
### Fixed
- Phase time input with size limit to avoid negative numbers

## [0.12.0] - 2020-11-25
### Added
- Alarm a sound when the timer ends
### Changed
- Ask for notification permission on start timer
### Fixed
- Fix useEffect to notify user and play sound

## [0.11.0] - 2020-11-12
### Added
- Notify user when timer ends

## [0.10.0] - 2020-11-07
### Fixed
- Switch Toggle Button
- Favicon
### Changed
- Disable `go to settings` and `back to app` according the app state

## [0.9.0] - 2020-11-02
### Changed
- Timer appearance (size)
### Fixed
- EditPhaseTime component time handling

## [0.8.0] - 2020-11-01
### Changed
- Redesign the layout

## [0.7.0] - 2020-10-31
### Added
- Skip timer button
### Fixed
- Button group width class

## [0.6.0] - 2020-10-31
### Added
- Count sessions

## [0.5.0] - 2020-10-31
### Added
- Use Button and Icon from reason-uikit lib
### Changed
- Stop timer after reset

## [0.4.0] - 2020-10-30
### Added
- Toggle Play/Pause button according current phase

## [0.3.0] - 2020-10-30
### Added
- Show current phase on screen (Focus/Break)

## [0.2.1] - 2020-10-29
### Added
- Button from reason-uikit

## [0.2.0] - 2020-10-27
### Added
- Working pomodoro application
- Styled with UIKit