<h1 align="center">
  <br>
  Pomodoro
</h1>

<h4 align="center">
  Pomodoro App with ReasonML and React.
</h4>
<p align="center">
  <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/tkovs/reason-pomodoro.svg">

  <img alt="GitHub language count" src="https://img.shields.io/github/languages/count/tkovs/reason-pomodoro.svg">
  
  <img alt="GitHub commit activity" src="https://img.shields.io/github/commit-activity/m/tkovs/reason-pomodoro.svg">

  <img alt="Repository size" src="https://img.shields.io/github/repo-size/tkovs/reason-pomodoro.svg">
  <br />
  <a href="https://github.com/tkovs/reason-pomodoro/commits/master">
    <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/tkovs/reason-pomodoro.svg">
  </a>

  <a href="https://github.com/tkovs/reason-pomodoro/issues">
    <img alt="Repository issues" src="https://img.shields.io/github/issues/tkovs/reason-pomodoro.svg">
  </a>

  <img alt="GitHub" src="https://img.shields.io/github/license/tkovs/reason-pomodoro.svg">
  <br />
  <img alt="Build status" src="https://api.netlify.com/api/v1/badges/c3404df3-bf7b-45b7-bc01-62175b0423d1/deploy-status">
</p>

<p align="center">
  <a href="#rocket-technologies">Technologies</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#information_source-how-to-run">How To Run</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#runner-next-steps">Next Steps</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#camera-screenshots">Screenshots</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#memo-license">License</a>
</p>

## :rocket: Technologies

This project was developed in my spare time with the following technologies:

-  [ReactJS](https://reactjs.org)
-  [ReasonML](https://reasonml.github.io)
-  [Reason UIKit](https://github.com/tkovs/reason-uikit)
-  [Testing Library](https://testing-library.com)

## :information_source: How To Run

To clone and run this application, you'll need [Git](https://git-scm.com), [Node.js][https://nodejs.org/en/] + [Yarn][https://yarnpkg.com/] (you can use npm instead) installed on your computer. From your command line:

```bash
# Clone this repository
$ git clone https://github.com/tkovs/reason-pomodoro
# Or
$ gh repo clone tkovs/reason-pomodoro

# Go into the repository
$ cd reason-pomodoro

# Install dependencies
$ yarn

# Run the app on two terminals
$ yarn start
$ yarn server

# Run the tests
$ yarn test

# Update snapshots
$ yarn test -u
```

## :runner: Next steps

- [x] Create Reason React project
- [x] Config webpack and babel
- [x] Create state and reducer
- [x] Implement layout desktop
- [x] Implement layout mobile
- [x] Handle state
- [x] Add unit tests for timer feature
- [x] Add unit tests for reset feature
- [x] Add unit tests for play feature
- [x] Add unit tests for pause feature
- [x] Add unit tests for jump feature
- [x] Add unit tests for session feature
- [ ] Add unit tests for settings feature
- [ ] Add unit tests for reducer
- [ ] Add cypress tests and configure GH Actions for pull requests
- [x] [Deploy](http://pomodoro.tkovs.com)
- [ ] Migrate html to [Reason UIKit](https://github.com/tkovs/reason-uikit)

## :camera: Screenshots

### Pomodoro
![image](https://user-images.githubusercontent.com/8717661/98301198-266bfa00-1f99-11eb-83b8-f11ec4efa93d.png)

### Settings
![image](https://user-images.githubusercontent.com/8717661/98301628-d5103a80-1f99-11eb-8ecd-cfe2a4418082.png)


## :memo: License
This project is under the MIT license. See the [LICENSE](https://github.com/tkovs/reason-pomodoro/blob/master/LICENSE) for more information.

---

Made with ♥ by tkovs :wave: [Get in touch!](https://www.linkedin.com/in/tkovs/)
