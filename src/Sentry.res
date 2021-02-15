type browserTracing

type integrations = {browserTracing: unit => browserTracing}

type config = {
  dsn: string,
  tracesSampleRate: float,
  integrations: array<browserTracing>,
}

@bs.module("@sentry/react") external init: config => unit = "init"
@bs.module("@sentry/tracing") @bs.scope("Integrations") @bs.new
external makeTracing: unit => browserTracing = "BrowserTracing"

let startSentry = () => {
  let params = {
    dsn: Environment.dsn,
    tracesSampleRate: 1.0,
    integrations: [makeTracing()],
  }

  init(params)
}
